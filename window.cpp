#include <iostream>
#include <GLFW/glfw3.h>

//TODO: does not use GLAD! This should be used for handling OS-specific calls
//e.g. Linux may call different GL functions compared to windows

/**
 * processInput() is a method recommended by LearnOpenGL. It performs a task when a key is pressed
 * NOTE: as this first project is self-contained, this method is defined in the class. This is not good practice and
 * future methods will be separated as necessary.
 * @param window - A pointer to a GLFWwindow object
 */
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    //Initialization
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //MacOS users: uncomment below \/
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //Create a window object; if it fails to create it will be NULL
    GLFWwindow* window = glfwCreateWindow(800, 600, "1 - Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    //Set this window as the current context
    glfwMakeContextCurrent(window);

    //A simple render loop provided by LearnOpenGL
    while(!glfwWindowShouldClose(window))
    {
        //Recommended order is:
        //  1. input
        //  2. render
        //  3. misc glfw
        processInput(window);

        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //when closing, free glfw's data and return 0
    glfwTerminate();
    return 0;
}