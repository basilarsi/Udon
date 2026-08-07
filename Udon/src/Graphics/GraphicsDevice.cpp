//
// Created by Basil on 8/6/2026.
//

#include "Udon/Graphics/GraphicsDevice.hpp"

namespace udon {
  /* No it can't */
  // ReSharper disable once CppVariableCanBeMadeConstexpr
  const std::vector ValidationLayers = {
    "VK_LAYER_KHRONOS_validation"
  };

  // ReSharper disable once CppVariableCanBeMadeConstexpr
  const std::vector RequiredDeviceExtension = {
    vk::KHRSwapchainExtensionName
  };

  std::vector<const char*> GetRequiredInstanceExtensions(const bool useValidation) {
    uint32 sdlExtensionCount = 0;
    /* TODO: This should be a udon::Window method. */
    const auto sdlExtensions = SDL_Vulkan_GetInstanceExtensions(&sdlExtensionCount);

    std::vector extensions(sdlExtensions, sdlExtensions + sdlExtensionCount);
    if (useValidation) {
      extensions.push_back(vk::EXTDebugUtilsExtensionName);
    }

    return extensions;
  }

  static VKAPI_ATTR vk::Bool32 VKAPI_CALL DebugCallback(vk::DebugUtilsMessageSeverityFlagBitsEXT      severity,
                                                        vk::DebugUtilsMessageTypeFlagsEXT             type,
                                                        const vk::DebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                        void*                                         pUserData) {
    switch (severity) {
      case vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose: {
        VK_VERBOSE(fmt::format("Validation message of type \"{}\": {}", to_string(type), pCallbackData->pMessage));
        break;
      }

      case vk::DebugUtilsMessageSeverityFlagBitsEXT::eInfo: {
        VK_INFO(fmt::format("Validation message of type \"{}\": {}", to_string(type), pCallbackData->pMessage));
        break;
      }

      case vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning: {
        VK_WARN(fmt::format("Validation message of type \"{}\": {}", to_string(type), pCallbackData->pMessage));
        break;
      }

      case vk::DebugUtilsMessageSeverityFlagBitsEXT::eError: {
        VK_ERROR(fmt::format("Validation message of type \"{}\": {}", to_string(type), pCallbackData->pMessage));
        break;
      }
    }
    return vk::False;
  }

  bool GraphicsDevice::SendConfig(const GraphicsDeviceCreateInfo& gfxdCreateInfo) {
    return true;
  }

  bool GraphicsDevice::Initialize() {
    auto gfxdCreateInfo = _gfxdCreateInfo ? *_gfxdCreateInfo : GraphicsDeviceCreateInfo{};

    //----------------------------------
    // INSTANCE CREATION
    //----------------------------------

    VK_VERBOSE("Attempting instance creation...");

    /* Layer Validation */
    std::vector<const char*> requiredLayers;
    if (gfxdCreateInfo.UseValidation) {
      /* quickly loop over the layers to see if Validation Layers are installed */
      const auto layers = _vulkan.enumerateInstanceLayerProperties();

      bool foundValidationLayers = false;
      for (const auto& layer : layers) {
        if (strcmp(layer.layerName, "VK_LAYER_KHRONOS_validation") == 0) {
          foundValidationLayers = true;
        }
      }

      if (foundValidationLayers) {
        requiredLayers.assign(ValidationLayers.begin(), ValidationLayers.end());
      } else {
        gfxdCreateInfo.UseValidation = false;
        VK_WARN("Validation Layers were requested, but couldn't be found! Are they installed?");
      }
    }

    auto layerProperties = _vulkan.enumerateInstanceLayerProperties();
    const auto unsupportedLayerIterator = std::ranges::find_if(requiredLayers, [&layerProperties](const auto& requiredLayer) {
      return std::ranges::none_of(layerProperties, [requiredLayer](const auto& layerProperty) {
        return strcmp(layerProperty.layerName, requiredLayer) == 0;
      });
    });
    if (unsupportedLayerIterator != requiredLayers.end()) {
      VK_FATAL(fmt::format("The required layer \"{}\" is not supported!", *unsupportedLayerIterator));
      return false;
    }

    /* Extension Validation */
    auto requiredExtensions = GetRequiredInstanceExtensions(gfxdCreateInfo.UseValidation);

    auto extensionProperties = _vulkan.enumerateInstanceExtensionProperties();
    const auto unsupportedPropertyInterator = std::ranges::find_if(requiredExtensions, [&extensionProperties](const auto& requiredExtension) {
      return std::ranges::none_of(extensionProperties, [requiredExtension](const auto& extensionProperty) {
        return strcmp(extensionProperty.extensionName, requiredExtension) == 0;
      });
    });
    if (unsupportedPropertyInterator != requiredExtensions.end()) {
      VK_FATAL(fmt::format("The required extension \"{}\" is not supported!", *unsupportedPropertyInterator));
      return false;
    }

    /* TODO: custom version wrapper */
    vk::ApplicationInfo applicationInfo{};
    applicationInfo.pApplicationName   = "DUMMY APP";
    applicationInfo.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
    applicationInfo.pEngineName        = "Udon";
    applicationInfo.engineVersion      = VK_MAKE_VERSION(0, 1, 0);
    applicationInfo.apiVersion         = vk::ApiVersion13;

    vk::InstanceCreateInfo instanceCreateInfo{};
    instanceCreateInfo.pApplicationInfo        = &applicationInfo;
    instanceCreateInfo.enabledLayerCount       = static_cast<uint32>(requiredLayers.size());
    instanceCreateInfo.ppEnabledLayerNames     = requiredLayers.data();
    instanceCreateInfo.enabledExtensionCount   = static_cast<uint32>(requiredExtensions.size());
    instanceCreateInfo.ppEnabledExtensionNames = requiredExtensions.data();

    _instance = vk::raii::Instance(_vulkan, instanceCreateInfo);

    //----------------------------------
    // DEBUG MESSENGER CREATION
    //----------------------------------

    VK_VERBOSE("Attempting debug messenger creation...");

    if (gfxdCreateInfo.UseValidation) {
      constexpr vk::DebugUtilsMessageSeverityFlagsEXT severityFlags(vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose |
                                                                    vk::DebugUtilsMessageSeverityFlagBitsEXT::eInfo    |
                                                                    vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning |
                                                                    vk::DebugUtilsMessageSeverityFlagBitsEXT::eError);
      constexpr vk::DebugUtilsMessageTypeFlagsEXT messageTypeFlags(vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral     |
                                                                   vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance |
                                                                   vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation);

      vk::DebugUtilsMessengerCreateInfoEXT debugMessengerCreateInfo{};
      debugMessengerCreateInfo.messageSeverity = severityFlags;
      debugMessengerCreateInfo.messageType     = messageTypeFlags;
      debugMessengerCreateInfo.pfnUserCallback = &DebugCallback;

      _debugMessenger = _instance.createDebugUtilsMessengerEXT(debugMessengerCreateInfo);
    }

    //----------------------------------
    // SURFACE CREATION
    //----------------------------------

    VK_VERBOSE("Attempting surface creation...");

    VkSurfaceKHR tempSurface = Window::CreateSurface(*_instance);
    if (tempSurface == nullptr) {
      VK_FATAL("Couldn't create the VkSurfaceKHR!");
      return false;
    }

    _surface                 = vk::raii::SurfaceKHR(_instance, tempSurface);

    //----------------------------------
    // PHYSICAL AND LOGICAL DEVICE
    //----------------------------------

    /* Physical Device */
    VK_VERBOSE("Attempting physical device creation...");

    const auto physicalDevices = _instance.enumeratePhysicalDevices();
    if (physicalDevices.empty()) {
      VK_FATAL("Couldn't find any GPUs with Vulkan support!");
      return false;
    }

    /* Super simple:tm: check for if a physical device is suitable... Right now it just grabs the first one that meets the requirements, needs to be more complete later. */
    for (const auto& device : physicalDevices) {
      const auto deviceProperties = device.getProperties();
      // ReSharper disable once CppTooWideScopeInitStatement
      const auto deviceFeatures   = device.getFeatures();

      if (deviceProperties.deviceType == vk::PhysicalDeviceType::eDiscreteGpu && deviceFeatures.tessellationShader && deviceProperties.apiVersion >= vk::ApiVersion13) {
        VK_VERBOSE(fmt::format("Found a suitable graphics card: \"{}\"", std::string(deviceProperties.deviceName)));
        _physicalDevice = device;
        break;
      }
    }

    if (_physicalDevice == nullptr) {
      VK_FATAL("Couldn't find a GPU that supports the features required by Udon!");
      return false;
    }

    /* Logical Device */
    VK_VERBOSE("Attempting logical device creation...");

    std::vector<vk::QueueFamilyProperties> queueFamilyProperties = _physicalDevice.getQueueFamilyProperties();

    uint32 queueIndex = ~0;
    for (uint32 qfpIndex = 0; qfpIndex < queueFamilyProperties.size(); qfpIndex++) {
      if ((queueFamilyProperties[qfpIndex].queueFlags & vk::QueueFlagBits::eGraphics) && _physicalDevice.getSurfaceSupportKHR(qfpIndex, *_surface)) {
        queueIndex = qfpIndex;
        break;
      }
    }

    if (queueIndex == ~0) {
      VK_FATAL("Couldn't find a queue for graphics and present!");
      return false;
    }

    float32 queuePriority = 0.5f;
    vk::DeviceQueueCreateInfo deviceQueueCreateInfo{};
    deviceQueueCreateInfo.queueFamilyIndex = queueIndex;
    deviceQueueCreateInfo.queueCount       = 1;
    deviceQueueCreateInfo.pQueuePriorities = &queuePriority;

    vk::PhysicalDeviceFeatures2 features2{};

    vk::PhysicalDeviceVulkan11Features features11{};
    features11.shaderDrawParameters = true;

    vk::PhysicalDeviceVulkan13Features features13{};
    features13.dynamicRendering = true;

    vk::PhysicalDeviceExtendedDynamicStateFeaturesEXT extendedDynamicStateFeatures{};
    extendedDynamicStateFeatures.extendedDynamicState = true;

    vk::StructureChain featureChain = {
      features2,
      features11,
      features13,
      extendedDynamicStateFeatures
    };

    vk::DeviceCreateInfo deviceCreateInfo{};
    deviceCreateInfo.pNext                   = &featureChain.get<vk::PhysicalDeviceFeatures2>();
    deviceCreateInfo.queueCreateInfoCount    = 1;
    deviceCreateInfo.pQueueCreateInfos       = &deviceQueueCreateInfo;
    deviceCreateInfo.enabledExtensionCount   = static_cast<uint32>(RequiredDeviceExtension.size());
    deviceCreateInfo.ppEnabledExtensionNames = RequiredDeviceExtension.data();

    _device        = vk::raii::Device(_physicalDevice, deviceCreateInfo);
    _graphicsQueue = vk::raii::Queue(_device, queueIndex, 0);

    //----------------------------------
    // SWAP CHAIN CREATION
    //----------------------------------

    VK_VERBOSE("Attempting swap chain creation...");

    const auto surfaceCapabilities = _physicalDevice.getSurfaceCapabilitiesKHR(*_surface);

    const auto availableFormats= _physicalDevice.getSurfaceFormatsKHR(*_surface);
    const auto availablePresentModes = _physicalDevice.getSurfacePresentModesKHR(*_surface);

    for (const auto& format : availableFormats) {
      VK_VERBOSE(to_string(format.format));
    }

    for (const auto& mode : availablePresentModes) {
      VK_VERBOSE(to_string(mode));
    }

    UDON_VERBOSE("Successfully initialized the Graphics Device.");
    return true;
  }

  void GraphicsDevice::Teardown() {
    _device.waitIdle();

    _surface.clear();
    _device.clear();
    _physicalDevice.clear();
    _debugMessenger.clear();
    _instance.clear();
  }
}
