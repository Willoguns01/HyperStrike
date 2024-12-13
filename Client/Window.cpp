#include "Window.hpp"

#include <mutex>

namespace HyperStrike
{
    namespace
    {
        std::mutex initMutex;
        static bool glfwIsInit = false;
        uint32_t numWindows = 0;

        Logger* logger = nullptr;

        void GLFWErrorCallback(int errorCode, const char* desc)
        {
            logger->Error("GLFW error code {0}: {1}", errorCode, desc);
        }
    }

    Window::Window(uint32_t width, uint32_t height, const std::string& name, Logger* logger)
    {
        _logger = logger;

        _windowWidth = width;
        _windowHeight = height;
        _windowName = name;

        std::unique_lock<std::mutex> initLock(initMutex);

        if (!glfwIsInit) {
            if (!glfwInit()) {
                _logger->Error("glfwInit error upon window creation");
                FlushGLFWErrors();
                return;
            }

            glfwIsInit = true;
            logger = _logger;

            glfwSetErrorCallback(&GLFWErrorCallback);
        }

        numWindows += 1;

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        _glfwWindow = glfwCreateWindow(_windowWidth, _windowHeight, name.c_str(), nullptr, nullptr);
        if (_glfwWindow == nullptr) {
            _logger->Error("glfwCreateWindow error upon window creation");
            return;
        }

        _logger->Info("Initialised window with name '{0}'", _windowName.c_str());
    }

    Window::~Window()
    {
        _logger->Info("Cleanup window '{0}'", _windowName.c_str());

        glfwDestroyWindow(_glfwWindow);

        initMutex.lock();

        numWindows -= 1;
        if (numWindows == 0) {
            glfwIsInit = false;
            glfwTerminate();
            _logger->Info("Terminated GLFW instance");
        }

        initMutex.unlock();
    }

    GLFWwindow* Window::GetGLFWWindow() const
    {
        return _glfwWindow;
    }

    VkSurfaceKHR Window::CreateWindowSurface(VkInstance vkInstance)
    {
        VkSurfaceKHR surface = NULL;
        VkResult err = glfwCreateWindowSurface(vkInstance, _glfwWindow, nullptr, &surface);
        if (err) {
            _logger->Error("Failed to create Vulkan surface from window '{0}'", _windowName.c_str());
            FlushGLFWErrors();
        }

        return surface;
    }

    void Window::FlushGLFWErrors()
    {
        const char* desc = nullptr;
        while (glfwGetError(&desc)) {
            _logger->Error("GLFW: {0}", desc);
            delete desc; // is this necessary?
        }
    }
}
