#pragma once

#include <Engine/Logger.hpp>

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include <string>

// TODO: platform-specific header includes, initialisation and handling
// we want this to work on both windows and linux

namespace HyperStrike
{
    class Window
    {
    public:
        Window(uint32_t width, uint32_t height, const std::string& name, Logger* logger);
        ~Window();

        GLFWwindow* GetGLFWWindow() const;

        VkSurfaceKHR CreateWindowSurface(VkInstance vkInstance);

    private:
        uint32_t _windowWidth = 0;
        uint32_t _windowHeight = 0;
        std::string _windowName;

        GLFWwindow* _glfwWindow = nullptr;

        Logger* _logger = nullptr;

        void FlushGLFWErrors();
    };
}
