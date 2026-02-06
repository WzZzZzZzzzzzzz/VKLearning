#pragma once
#include "EasyVKStart.h"
#include "vulkan/vulkan_core.h"
#include <cstring>
#include <vector>
#include <wingdi.h>
//定义vulkan命名空间，之后会把Vulkan中一些基本对象的封装写在其中
namespace vulkan {
    class graphicsBase {
    private:
        VkInstance instance;
        VkPhysicalDevice physicalDevice;
        VkPhysicalDeviceProperties physicalDeviceProperties;
        VkPhysicalDeviceMemoryProperties physicalDeviceMemoryProperties;
        std::vector<VkPhysicalDevice> availablePhysicalDevices;

        VkDevice device;
        uint32_t queueFamilyIndex_graphics = VK_QUEUE_FAMILY_IGNORED;
        uint32_t queueFamilyIndex_presentation = VK_QUEUE_FAMILY_IGNORED;
        uint32_t queueFamilyIndex_compute = VK_QUEUE_FAMILY_IGNORED;
        VkQueue queue_graphics;
        VkQueue queue_presentation;
        VkQueue queue_compute;

        VkSurfaceKHR surface;
        std::vector <VkSurfaceFormatKHR> availableSurfaceFormats;

        VkSwapchainKHR swapchain;
        std::vector <VkImage> swapchainImages;
        std::vector <VkImageView> swapchainImageViews;
        VkSwapchainCreateInfoKHR swapchainCreateInfo = {};

        std::vector<const char*> instanceLayers;
        std::vector<const char*> instanceExtensions;
        std::vector<const char*> deviceExtensions;
        
        VkDebugUtilsMessengerEXT debugMessenger;

        static graphicsBase singleton;

        graphicsBase() = default;
        graphicsBase(graphicsBase&&) = delete;
        ~graphicsBase() {
            
        }
        static void AddLayerOrExtension(std::vector<const char*>& container, const char* name) {
            for (auto& i : container)
                if (!strcmp(name, i)) return;
            container.push_back(name);
        }
        VkResult CreateDebugMessenger() {
            // for1.3
        }
        VkResult GetQueueFamilyIndices(VkPhysicalDevice physicalDevice, bool enableGraphicsQueue, bool enableComputeQueue, uint32_t (&queueFamilyIndices)[3]) {
            // for1.3
        }
        VkResult CreateSwapchain_Internal() {
            // for1.4
        }

    public:
        // Getter
        VkInstance Instance() const {
            return instance;
        }
        const std::vector<const char*>& InstanceLayers() const {
            return instanceLayers;
        }
        const std::vector<const char*>& IstanceExtensions() const {
            return instanceExtensions;
        }
        VkSurfaceKHR Surface() const {
            return surface;
        }

        VkPhysicalDevice PhysicalDevice() const {
            return physicalDevice;
        }
        const VkPhysicalDeviceProperties& PhysicalDeviceProperties() const {
            return physicalDeviceProperties;
        }
        const VkPhysicalDeviceMemoryProperties& PhysicalDeviceMemoryProperties() const {
            return physicalDeviceMemoryProperties;
        }
        VkPhysicalDevice AvailablePhysicalDevice(uint32_t index) const {
            return availablePhysicalDevices[index];
        }
        uint32_t AvailablePhysicalDeviceCount() const {
            return uint32_t(availablePhysicalDevices.size());
        }

        VkDevice Device() const {
            return device;
        }
        uint32_t QueueFamilyIndex_Graphics() const {
            return queueFamilyIndex_graphics;
        }
        uint32_t QueueFamilyIndex_Presentation() const {
            return queueFamilyIndex_presentation;
        }
        uint32_t QueueFamilyIndex_Compute() const {
            return queueFamilyIndex_compute;
        }
        VkQueue Queue_Graphics() const {
            return queue_graphics;
        }
        VkQueue Queue_Presentation() const {
            return queue_presentation;
        }
        VkQueue Queue_Compute() const {
            return queue_compute;
        }

        const std::vector<const char*>& DeviceExtensions() const {
            return deviceExtensions;
        }

        const VkFormat& AvailableSurfaceFormat(uint32_t index) const {
            return availableSurfaceFormats[index].format;
        }
        const VkColorSpaceKHR& AvailableSurfaceColorSpace(uint32_t index) const {
            return availableSurfaceFormats[index].colorSpace;
        }
        uint32_t AvailableSurfaceFormatCount() const {
            return uint32_t(availableSurfaceFormats.size());
        }

        VkSwapchainKHR Swapchain() const {
            return swapchain;
        }
        VkImage SwapchainImage(uint32_t index) const {
            return swapchainImages[index];
        }
        VkImageView SwapchainImageView(uint32_t index) const {
            return swapchainImageViews[index];
        }
        uint32_t SwapchainImageCount() const {
            return uint32_t(swapchainImages.size());
        }
        const VkSwapchainCreateInfoKHR& SwapchainCreateInfo() const {
            return swapchainCreateInfo;
        }

        void AddInstanceLayer (const char* layername) {
            AddLayerOrExtension(instanceLayers, layername);
        }
        void AddInstanceExtension (const char* extensionName) {
            AddLayerOrExtension(instanceExtensions, extensionName);          
        }
        void Surface(VkSurfaceKHR surface) {
            if (!this->surface)
                this->surface = surface;
        }

        VkResult CreateInstance(VkInstanceCreateFlags flags = 0) {
            // for1.3
        }
        VkResult CheckInstanceLayers(std::span<const char*> layerToCheck) {
            // for1.3
        }
        void InstanceLayers(const std::vector<const char*>& layerNames) {
            instanceLayers = layerNames;
        }
        VkResult CheckInstanceExtensions(std::span<const char*> extensionsToCheck, const char* layerName = nullptr) const {
            // for1.3
        }
        void InstanceExtensions(const std::vector<const char*>& extensionName) {
            instanceExtensions = extensionName;
        }

        void AddDeviceExtension(const char* extensionName) {
            AddLayerOrExtension(deviceExtensions, extensionName);
        }
        VkResult GetPhysicalDevices() {
            // for1.3
        }
        VkResult DeterminePhysicalDevice(uint32_t deviceIndex = 0, bool enableGraphicsQueue, bool enableComputeQueue = true) {
            // for1.3
        }
        VkResult CreateDevice(VkDeviceCreateFlags flags = 0) {
            // for1.3
        }
        VkResult CheckDeviceExtensions(std::span<const char*> extensionsToCheck, const char* layerName = nullptr) const {
            // for1.3
        }
        void DeviceExtensions(const std::vector<const char*>& extensionNames) {
            // for1.3
        }
        VkResult GetSurfaceFormats() {
            // for1.4
        }
        VkResult SetSurfaceFormat(VkSurfaceFormatKHR surfaceFormat) {
            // for1.4
        }
        VkResult CreateSwapchain(bool limitFrameRate = true, VkSwapchainCreateFlagsKHR flags = 0) {
            // for1.4
        }
        VkResult RecreateSwapchain() {
            // for1.4
        }
        static graphicsBase& Base() {
            return singleton;
        }
    };
    inline graphicsBase graphicsBase::singleton;
}