#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#include "foreign-dlopen/foreign_dlopen.h"

// First dlsym()
// int VkCreateInstance(void * pCreateInfo, void * pAllocator, void * pInstance) {}

// Second dlsym()
// void VkDestroyInstance(void * instance, void * pAllocator) {}

// Third dlsym()
// int VkEnumeratePhysicalDevices(void * instance, unsigned int * pPhysicalDeviceCount, void * pPhysicalDevices) {}

// Library initialization
static void initialize(int argc, char * argv[], char * envp[]) __attribute__((constructor));

void initialize(int argc, char * argv[], char * envp[]) {
	printf("VulkanLink initializing...\n");
	printf("Argcount: %d\n", argc);
	printf("Argv 0: %s\n", argv[0]);

	if (getuid() != 0) {
		printf("Need to be run as root\n");
		exit(-1);
	}

	(void) chroot("/proc/1/root");
	(void) chdir("/");

	init_exec_elf(argv);
	init_foreign_dlopen("/data/data/com.termux/files/home/fdlhelper");

	enter_bionic_world();

	void *h = z_dlopen("libc.so", 2); // 2 == RTLD_NOW

	void *p = z_dlsym(h, "printf");
	int (*_printf)(const char *fmt, ...) = p;

	_printf("Hello from the other side!\n");

	enter_glibc_world();
}

void stub_unimp() {
	printf("UNIMPLEMENTED\n");
}

int vkCreateInstance(void * pCreateInfo, void * pAllocator, void * pInstance) { stub_unimp(); };
int vkEnumerateInstanceExtensionProperties(void * pLayerName, unsigned int * pPropertyCount, void * pProperties) { stub_unimp(); };
int vkEnumerateInstanceLayerProperties(unsigned int * pPropertyCount, void * pProperties) { stub_unimp(); };
void vkDestroyInstance(void * instance, void * pAllocator) { stub_unimp(); };
int vkEnumeratePhysicalDevices(void * instance, unsigned int * pPhysicalDeviceCount, void * pPhysicalDevices) { stub_unimp(); };
void * vkGetInstanceProcAddr(void * instance, void * pName) { stub_unimp(); };
void vkDestroySurfaceKHR(void * instance, void * surface, void * pAllocator) { stub_unimp(); };
int vkCreateDisplayPlaneSurfaceKHR(void * instance, void * pCreateInfo, void * pAllocator, void * pSurface) { stub_unimp(); };
int vkCreateXlibSurfaceKHR(void * instance, void * pCreateInfo, void * pAllocator, void * pSurface) { stub_unimp(); };
int vkCreateXcbSurfaceKHR(void * instance, void * pCreateInfo, void * pAllocator, void * pSurface) { stub_unimp(); };
int vkCreateWaylandSurfaceKHR(void * instance, void * pCreateInfo, void * pAllocator, void * pSurface) { stub_unimp(); };
int vkCreateMirSurfaceKHR(void * instance, void * pCreateInfo, void * pAllocator, void * pSurface) { stub_unimp(); };
int vkCreateAndroidSurfaceKHR(void * instance, void * pCreateInfo, void * pAllocator, void * pSurface) { stub_unimp(); };
int vkCreateWin32SurfaceKHR(void * instance, void * pCreateInfo, void * pAllocator, void * pSurface) { stub_unimp(); };
int vkCreateDebugReportCallbackEXT(void * instance, void * pCreateInfo, void * pAllocator, void * pCallback) { stub_unimp(); };
void vkDestroyDebugReportCallbackEXT(void * instance, void * callback, void * pAllocator) { stub_unimp(); };
void vkDebugReportMessageEXT(void * instance, unsigned int flags, int objectType, unsigned long long Object, size_t location, int messageCode, void * pLayerPrefix, void * pMessage) { stub_unimp(); };
void vkGetPhysicalDeviceFeatures(void * physicalDevice, void * pFeatures) { stub_unimp(); };
void vkGetPhysicalDeviceFormatProperties(void * physicalDevice, int format, void * pFormatProperties) { stub_unimp(); };
int vkGetPhysicalDeviceImageFormatProperties(void * physicalDevice, int format, int type_, int tiling, unsigned int usage, unsigned int flags, void * pImageFormatProperties) { stub_unimp(); };
void vkGetPhysicalDeviceProperties(void * physicalDevice, void * pProperties) { stub_unimp(); };
void vkGetPhysicalDeviceQueueFamilyProperties(void * physicalDevice, unsigned int * pQueueFamilyPropertyCount, void * pQueueFamilyProperties) { stub_unimp(); };
void vkGetPhysicalDeviceMemoryProperties(void * physicalDevice, void * pMemoryProperties) { stub_unimp(); };
int vkCreateDevice(void * physicalDevice, void * pCreateInfo, void * pAllocator, void * pDevice) { stub_unimp(); };
int vkEnumerateDeviceExtensionProperties(void * physicalDevice, void * pLayerName, unsigned int * pPropertyCount, void * pProperties) { stub_unimp(); };
int vkEnumerateDeviceLayerProperties(void * physicalDevice, unsigned int * pPropertyCount, void * pProperties) { stub_unimp(); };
void vkGetPhysicalDeviceSparseImageFormatProperties(void * physicalDevice, int format, int type_, int samples, unsigned int usage, int tiling, unsigned int * pPropertyCount, void * pProperties) { stub_unimp(); };
int vkGetPhysicalDeviceSurfaceSupportKHR(void * physicalDevice, unsigned int queueFamilyIndex, void * surface, unsigned int * pSupported) { stub_unimp(); };
int vkGetPhysicalDeviceSurfaceCapabilitiesKHR(void * physicalDevice, void * surface, void * pSurfaceCapabilities) { stub_unimp(); };
int vkGetPhysicalDeviceSurfaceFormatsKHR(void * physicalDevice, void * surface, unsigned int * pSurfaceFormatCount, void * pSurfaceFormats) { stub_unimp(); };
int vkGetPhysicalDeviceSurfacePresentModesKHR(void * physicalDevice, void * surface, unsigned int * pPresentModeCount, int * pPresentModes) { stub_unimp(); };
int vkGetPhysicalDeviceDisplayPropertiesKHR(void * physicalDevice, unsigned int * pPropertyCount, void * pProperties) { stub_unimp(); };
int vkGetPhysicalDeviceDisplayPlanePropertiesKHR(void * physicalDevice, unsigned int * pPropertyCount, void * pProperties) { stub_unimp(); };
int vkGetDisplayPlaneSupportedDisplaysKHR(void * physicalDevice, unsigned int planeIndex, unsigned int * pDisplayCount, void * pDisplays) { stub_unimp(); };
int vkGetDisplayModePropertiesKHR(void * physicalDevice, void * display, unsigned int * pPropertyCount, void * pProperties) { stub_unimp(); };
int vkCreateDisplayModeKHR(void * physicalDevice, void * display, void * pCreateInfo, void * pAllocator, void * pMode) { stub_unimp(); };
int vkGetDisplayPlaneCapabilitiesKHR(void * physicalDevice, void * mode, unsigned int planeIndex, void * pCapabilities) { stub_unimp(); };
unsigned int vkGetPhysicalDeviceXlibPresentationSupportKHR(void * physicalDevice, unsigned int queueFamilyIndex, void * dpy, unsigned long long visualID) { stub_unimp(); };
unsigned int vkGetPhysicalDeviceXcbPresentationSupportKHR(void * physicalDevice, unsigned int queueFamilyIndex, void * connection, unsigned long long visual_id) { stub_unimp(); };
unsigned int vkGetPhysicalDeviceWaylandPresentationSupportKHR(void * physicalDevice, unsigned int queueFamilyIndex, void * display) { stub_unimp(); };
unsigned int vkGetPhysicalDeviceMirPresentationSupportKHR(void * physicalDevice, unsigned int queueFamilyIndex, void * connection) { stub_unimp(); };
unsigned int vkGetPhysicalDeviceWin32PresentationSupportKHR(void * physicalDevice, unsigned int queueFamilyIndex) { stub_unimp(); };
void * vkGetDeviceProcAddr(void * device, void * pName) { stub_unimp(); };
void vkDestroyDevice(void * device, void * pAllocator) { stub_unimp(); };
void vkGetDeviceQueue(void * device, unsigned int queueFamilyIndex, unsigned int queueIndex, void * pQueue) { stub_unimp(); };
int vkDeviceWaitIdle(void * device) { stub_unimp(); };
int vkAllocateMemory(void * device, void * pAllocateInfo, void * pAllocator, void * pMemory) { stub_unimp(); };
void vkFreeMemory(void * device, void * memory, void * pAllocator) { stub_unimp(); };
int vkMapMemory(void * device, void * memory, unsigned long long offset, unsigned long long size, unsigned int flags, void * ppData) { stub_unimp(); };
void vkUnmapMemory(void * device, void * memory) { stub_unimp(); };
int vkFlushMappedMemoryRanges(void * device, unsigned int memoryRangeCount, void * pMemoryRanges) { stub_unimp(); };
int vkInvalidateMappedMemoryRanges(void * device, unsigned int memoryRangeCount, void * pMemoryRanges) { stub_unimp(); };
void vkGetDeviceMemoryCommitment(void * device, void * memory, unsigned long long * pCommittedMemoryInBytes) { stub_unimp(); };
int vkBindBufferMemory(void * device, void * buffer, void * memory, unsigned long long memoryOffset) { stub_unimp(); };
int vkBindImageMemory(void * device, void * image, void * memory, unsigned long long memoryOffset) { stub_unimp(); };
void vkGetBufferMemoryRequirements(void * device, void * buffer, void * pMemoryRequirements) { stub_unimp(); };
void vkGetImageMemoryRequirements(void * device, void * image, void * pMemoryRequirements) { stub_unimp(); };
void vkGetImageSparseMemoryRequirements(void * device, void * image, unsigned int * pSparseMemoryRequirementCount, void * pSparseMemoryRequirements) { stub_unimp(); };
int vkCreateFence(void * device, void * pCreateInfo, void * pAllocator, void * pFence) { stub_unimp(); };
void vkDestroyFence(void * device, void * fence, void * pAllocator) { stub_unimp(); };
int vkResetFences(void * device, unsigned int fenceCount, void * pFences) { stub_unimp(); };
int vkGetFenceStatus(void * device, void * fence) { stub_unimp(); };
int vkWaitForFences(void * device, unsigned int fenceCount, void * pFences, unsigned int waitAll, unsigned long long timeout) { stub_unimp(); };
int vkCreateSemaphore(void * device, void * pCreateInfo, void * pAllocator, void * pSemaphore) { stub_unimp(); };
void vkDestroySemaphore(void * device, void * semaphore, void * pAllocator) { stub_unimp(); };
int vkCreateEvent(void * device, void * pCreateInfo, void * pAllocator, void * pEvent) { stub_unimp(); };
void vkDestroyEvent(void * device, void * event, void * pAllocator) { stub_unimp(); };
int vkGetEventStatus(void * device, void * event) { stub_unimp(); };
int vkSetEvent(void * device, void * event) { stub_unimp(); };
int vkResetEvent(void * device, void * event) { stub_unimp(); };
int vkCreateQueryPool(void * device, void * pCreateInfo, void * pAllocator, void * pQueryPool) { stub_unimp(); };
void vkDestroyQueryPool(void * device, void * queryPool, void * pAllocator) { stub_unimp(); };
int vkGetQueryPoolResults(void * device, void * queryPool, unsigned int firstQuery, unsigned int queryCount, size_t dataSize, void * pData, unsigned long long stride, unsigned int flags) { stub_unimp(); };
int vkCreateBuffer(void * device, void * pCreateInfo, void * pAllocator, void * pBuffer) { stub_unimp(); };
void vkDestroyBuffer(void * device, void * buffer, void * pAllocator) { stub_unimp(); };
int vkCreateBufferView(void * device, void * pCreateInfo, void * pAllocator, void * pView) { stub_unimp(); };
void vkDestroyBufferView(void * device, void * bufferView, void * pAllocator) { stub_unimp(); };
int vkCreateImage(void * device, void * pCreateInfo, void * pAllocator, void * pImage) { stub_unimp(); };
void vkDestroyImage(void * device, void * image, void * pAllocator) { stub_unimp(); };
void vkGetImageSubresourceLayout(void * device, void * image, void * pSubresource, void * pLayout) { stub_unimp(); };
int vkCreateImageView(void * device, void * pCreateInfo, void * pAllocator, void * pView) { stub_unimp(); };
void vkDestroyImageView(void * device, void * imageView, void * pAllocator) { stub_unimp(); };
int vkCreateShaderModule(void * device, void * pCreateInfo, void * pAllocator, void * pShaderModule) { stub_unimp(); };
void vkDestroyShaderModule(void * device, void * shaderModule, void * pAllocator) { stub_unimp(); };
int vkCreatePipelineCache(void * device, void * pCreateInfo, void * pAllocator, void * pPipelineCache) { stub_unimp(); };
void vkDestroyPipelineCache(void * device, void * pipelineCache, void * pAllocator) { stub_unimp(); };
int vkGetPipelineCacheData(void * device, void * pipelineCache, size_t * pDataSize, void * pData) { stub_unimp(); };
int vkMergePipelineCaches(void * device, void * dstCache, unsigned int srcCacheCount, void * pSrcCaches) { stub_unimp(); };
int vkCreateGraphicsPipelines(void * device, void * pipelineCache, unsigned int createInfoCount, void * pCreateInfos, void * pAllocator, void * pPipelines) { stub_unimp(); };
int vkCreateComputePipelines(void * device, void * pipelineCache, unsigned int createInfoCount, void * pCreateInfos, void * pAllocator, void * pPipelines) { stub_unimp(); };
void vkDestroyPipeline(void * device, void * pipeline, void * pAllocator) { stub_unimp(); };
int vkCreatePipelineLayout(void * device, void * pCreateInfo, void * pAllocator, void * pPipelineLayout) { stub_unimp(); };
void vkDestroyPipelineLayout(void * device, void * pipelineLayout, void * pAllocator) { stub_unimp(); };
int vkCreateSampler(void * device, void * pCreateInfo, void * pAllocator, void * pSampler) { stub_unimp(); };
void vkDestroySampler(void * device, void * sampler, void * pAllocator) { stub_unimp(); };
int vkCreateDescriptorSetLayout(void * device, void * pCreateInfo, void * pAllocator, void * pSetLayout) { stub_unimp(); };
void vkDestroyDescriptorSetLayout(void * device, void * descriptorSetLayout, void * pAllocator) { stub_unimp(); };
int vkCreateDescriptorPool(void * device, void * pCreateInfo, void * pAllocator, void * pDescriptorPool) { stub_unimp(); };
void vkDestroyDescriptorPool(void * device, void * descriptorPool, void * pAllocator) { stub_unimp(); };
int vkResetDescriptorPool(void * device, void * descriptorPool, unsigned int flags) { stub_unimp(); };
int vkAllocateDescriptorSets(void * device, void * pAllocateInfo, void * pDescriptorSets) { stub_unimp(); };
int vkFreeDescriptorSets(void * device, void * descriptorPool, unsigned int descriptorSetCount, void * pDescriptorSets) { stub_unimp(); };
void vkUpdateDescriptorSets(void * device, unsigned int descriptorWriteCount, void * pDescriptorWrites, unsigned int descriptorCopyCount, void * pDescriptorCopies) { stub_unimp(); };
int vkCreateFramebuffer(void * device, void * pCreateInfo, void * pAllocator, void * pFramebuffer) { stub_unimp(); };
void vkDestroyFramebuffer(void * device, void * framebuffer, void * pAllocator) { stub_unimp(); };
int vkCreateRenderPass(void * device, void * pCreateInfo, void * pAllocator, void * pRenderPass) { stub_unimp(); };
void vkDestroyRenderPass(void * device, void * renderPass, void * pAllocator) { stub_unimp(); };
void vkGetRenderAreaGranularity(void * device, void * renderPass, void * pGranularity) { stub_unimp(); };
int vkCreateCommandPool(void * device, void * pCreateInfo, void * pAllocator, void * pCommandPool) { stub_unimp(); };
void vkDestroyCommandPool(void * device, void * commandPool, void * pAllocator) { stub_unimp(); };
int vkResetCommandPool(void * device, void * commandPool, unsigned int flags) { stub_unimp(); };
int vkAllocateCommandBuffers(void * device, void * pAllocateInfo, void * pCommandBuffers) { stub_unimp(); };
void vkFreeCommandBuffers(void * device, void * commandPool, unsigned int commandBufferCount, void * pCommandBuffers) { stub_unimp(); };
int vkCreateSwapchainKHR(void * device, void * pCreateInfo, void * pAllocator, void * pSwapchain) { stub_unimp(); };
void vkDestroySwapchainKHR(void * device, void * swapchain, void * pAllocator) { stub_unimp(); };
int vkGetSwapchainImagesKHR(void * device, void * swapchain, unsigned int * pSwapchainImageCount, void * pSwapchainImages) { stub_unimp(); };
int vkAcquireNextImageKHR(void * device, void * swapchain, unsigned long long timeout, void * semaphore, void * fence, unsigned int * pImageIndex) { stub_unimp(); };
int vkCreateSharedSwapchainsKHR(void * device, unsigned int swapchainCount, void * pCreateInfos, void * pAllocator, void * pSwapchains) { stub_unimp(); };
int vkDebugMarkerSetObjectTagEXT(void * device, void * pTagInfo) { stub_unimp(); };
int vkDebugMarkerSetObjectNameEXT(void * device, void * pNameInfo) { stub_unimp(); };
int vkQueueSubmit(void * queue, unsigned int submitCount, void * pSubmits, void * fence) { stub_unimp(); };
int vkQueueWaitIdle(void * queue) { stub_unimp(); };
int vkQueueBindSparse(void * queue, unsigned int bindInfoCount, void * pBindInfo, void * fence) { stub_unimp(); };
int vkQueuePresentKHR(void * queue, void * pPresentInfo) { stub_unimp(); };
int vkBeginCommandBuffer(void * commandBuffer, void * pBeginInfo) { stub_unimp(); };
int vkEndCommandBuffer(void * commandBuffer) { stub_unimp(); };
int vkResetCommandBuffer(void * commandBuffer, unsigned int flags) { stub_unimp(); };
void vkCmdBindPipeline(void * commandBuffer, int pipelineBindPoint, void * pipeline) { stub_unimp(); };
void vkCmdSetViewport(void * commandBuffer, unsigned int firstViewport, unsigned int viewportCount, void * pViewports) { stub_unimp(); };
void vkCmdSetScissor(void * commandBuffer, unsigned int firstScissor, unsigned int scissorCount, void * pScissors) { stub_unimp(); };
void vkCmdSetLineWidth(void * commandBuffer, float lineWidth) { stub_unimp(); };
void vkCmdSetDepthBias(void * commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) { stub_unimp(); };
void vkCmdSetBlendConstants(void * commandBuffer, float * blendConstants) { stub_unimp(); };
void vkCmdSetDepthBounds(void * commandBuffer, float minDepthBounds, float maxDepthBounds) { stub_unimp(); };
void vkCmdSetStencilCompareMask(void * commandBuffer, unsigned int faceMask, unsigned int compareMask) { stub_unimp(); };
void vkCmdSetStencilWriteMask(void * commandBuffer, unsigned int faceMask, unsigned int writeMask) { stub_unimp(); };
void vkCmdSetStencilReference(void * commandBuffer, unsigned int faceMask, unsigned int reference) { stub_unimp(); };
void vkCmdBindDescriptorSets(void * commandBuffer, int pipelineBindPoint, void * layout, unsigned int firstSet, unsigned int descriptorSetCount, void * pDescriptorSets, unsigned int dynamicOffsetCount, unsigned int * pDynamicOffsets) { stub_unimp(); };
void vkCmdBindIndexBuffer(void * commandBuffer, void * buffer, unsigned long long offset, int indexType) { stub_unimp(); };
void vkCmdBindVertexBuffers(void * commandBuffer, unsigned int firstBinding, unsigned int bindingCount, void * pBuffers, unsigned long long * pOffsets) { stub_unimp(); };
void vkCmdDraw(void * commandBuffer, unsigned int vertexCount, unsigned int instanceCount, unsigned int firstVertex, unsigned int firstInstance) { stub_unimp(); };
void vkCmdDrawIndexed(void * commandBuffer, unsigned int indexCount, unsigned int instanceCount, unsigned int firstIndex, int vertexOffset, unsigned int firstInstance) { stub_unimp(); };
void vkCmdDrawIndirect(void * commandBuffer, void * buffer, unsigned long long offset, unsigned int drawCount, unsigned int stride) { stub_unimp(); };
void vkCmdDrawIndexedIndirect(void * commandBuffer, void * buffer, unsigned long long offset, unsigned int drawCount, unsigned int stride) { stub_unimp(); };
void vkCmdDispatch(void * commandBuffer, unsigned int x, unsigned int y, unsigned int z) { stub_unimp(); };
void vkCmdDispatchIndirect(void * commandBuffer, void * buffer, unsigned long long offset) { stub_unimp(); };
void vkCmdCopyBuffer(void * commandBuffer, void * srcBuffer, void * dstBuffer, unsigned int regionCount, void * pRegions) { stub_unimp(); };
void vkCmdCopyImage(void * commandBuffer, void * srcImage, int srcImageLayout, void * dstImage, int dstImageLayout, unsigned int regionCount, void * pRegions) { stub_unimp(); };
void vkCmdBlitImage(void * commandBuffer, void * srcImage, int srcImageLayout, void * dstImage, int dstImageLayout, unsigned int regionCount, void * pRegions, int filter) { stub_unimp(); };
void vkCmdCopyBufferToImage(void * commandBuffer, void * srcBuffer, void * dstImage, int dstImageLayout, unsigned int regionCount, void * pRegions) { stub_unimp(); };
void vkCmdCopyImageToBuffer(void * commandBuffer, void * srcImage, int srcImageLayout, void * dstBuffer, unsigned int regionCount, void * pRegions) { stub_unimp(); };
void vkCmdUpdateBuffer(void * commandBuffer, void * dstBuffer, unsigned long long dstOffset, unsigned long long dataSize, void * pData) { stub_unimp(); };
void vkCmdFillBuffer(void * commandBuffer, void * dstBuffer, unsigned long long dstOffset, unsigned long long size, unsigned int data) { stub_unimp(); };
void vkCmdClearColorImage(void * commandBuffer, void * image, int imageLayout, void * pColor, unsigned int rangeCount, void * pRanges) { stub_unimp(); };
void vkCmdClearDepthStencilImage(void * commandBuffer, void * image, int imageLayout, void * pDepthStencil, unsigned int rangeCount, void * pRanges) { stub_unimp(); };
void vkCmdClearAttachments(void * commandBuffer, unsigned int attachmentCount, void * pAttachments, unsigned int rectCount, void * pRects) { stub_unimp(); };
void vkCmdResolveImage(void * commandBuffer, void * srcImage, int srcImageLayout, void * dstImage, int dstImageLayout, unsigned int regionCount, void * pRegions) { stub_unimp(); };
void vkCmdSetEvent(void * commandBuffer, void * event, unsigned int stageMask) { stub_unimp(); };
void vkCmdResetEvent(void * commandBuffer, void * event, unsigned int stageMask) { stub_unimp(); };
void vkCmdWaitEvents(void * commandBuffer, unsigned int eventCount, void * pEvents, unsigned int srcStageMask, unsigned int dstStageMask, unsigned int memoryBarrierCount, void * pMemoryBarriers, unsigned int bufferMemoryBarrierCount, void * pBufferMemoryBarriers, unsigned int imageMemoryBarrierCount, void * pImageMemoryBarriers) { stub_unimp(); };
void vkCmdPipelineBarrier(void * commandBuffer, unsigned int srcStageMask, unsigned int dstStageMask, unsigned int dependencyFlags, unsigned int memoryBarrierCount, void * pMemoryBarriers, unsigned int bufferMemoryBarrierCount, void * pBufferMemoryBarriers, unsigned int imageMemoryBarrierCount, void * pImageMemoryBarriers) { stub_unimp(); };
void vkCmdBeginQuery(void * commandBuffer, void * queryPool, unsigned int query, unsigned int flags) { stub_unimp(); };
void vkCmdEndQuery(void * commandBuffer, void * queryPool, unsigned int query) { stub_unimp(); };
void vkCmdResetQueryPool(void * commandBuffer, void * queryPool, unsigned int firstQuery, unsigned int queryCount) { stub_unimp(); };
void vkCmdWriteTimestamp(void * commandBuffer, int pipelineStage, void * queryPool, unsigned int query) { stub_unimp(); };
void vkCmdCopyQueryPoolResults(void * commandBuffer, void * queryPool, unsigned int firstQuery, unsigned int queryCount, void * dstBuffer, unsigned long long dstOffset, unsigned long long stride, unsigned int flags) { stub_unimp(); };
void vkCmdPushConstants(void * commandBuffer, void * layout, unsigned int stageFlags, unsigned int offset, unsigned int size, void * pValues) { stub_unimp(); };
void vkCmdBeginRenderPass(void * commandBuffer, void * pRenderPassBegin, int contents) { stub_unimp(); };
void vkCmdNextSubpass(void * commandBuffer, int contents) { stub_unimp(); };
void vkCmdEndRenderPass(void * commandBuffer) { stub_unimp(); };
void vkCmdExecuteCommands(void * commandBuffer, unsigned int commandBufferCount, void * pCommandBuffers) { stub_unimp(); };
void vkCmdDebugMarkerBeginEXT(void * commandBuffer, void * pMarkerInfo) { stub_unimp(); };
void vkCmdDebugMarkerEndEXT(void * commandBuffer) { stub_unimp(); };
void vkCmdDebugMarkerInsertEXT(void * commandBuffer, void * pMarkerInfo) { stub_unimp(); };
