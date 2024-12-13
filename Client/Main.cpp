#include "Window.hpp"

#include <Engine/Logger.hpp>

#include <iostream>

void ResizeCallback(GLFWwindow* window, int width, int height)
{
    HyperStrike::Logger* logger = static_cast<HyperStrike::Logger*>(glfwGetWindowUserPointer(window));
    logger->Info("Resized window: {0}x{1}", width, height);
}

int main()
{
    HyperStrike::Logger logger("Client");
    logger.Info("Hello from HyperStrike Client!");

    HyperStrike::Window window(1600, 900, "Test Window", &logger);
    GLFWwindow* glfwWindow = window.GetGLFWWindow();

    glfwSetWindowUserPointer(glfwWindow, &logger);
    glfwSetFramebufferSizeCallback(glfwWindow, ResizeCallback);

    logger.Info("Initialised client");

    while (!glfwWindowShouldClose(glfwWindow)) {
        glfwPollEvents();
    }

    return 0;
}
