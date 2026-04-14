#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// прототип коллбека для изменения размера окна
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
    // инициализируем glfw
    glfwInit();
    // указываем, что мы будем использовать OpenGL 3.x версии
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // указываем, что мы будем использовать OpenGL x.3 версии.
    // В данном случае, получается, что мы используем OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // указывем, что используем Core
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // создаём объект окна размером 800x600 пикселей, с названием CREATING WINDOW OR SMTH. Всё остальное будет NULL
    GLFWwindow* window = glfwCreateWindow(800, 600, "CREATING WINDOW OR SMTH", nullptr, nullptr);
    // если окно не создалось, то выводим сообщение об этом и очищаем всё, что связано с glfw
    if (window == nullptr) {
        std::cout << "[-] failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // создать контекст нашего окна
    glfwMakeContextCurrent(window);

    // если не получилось найти glfwGetProcAddress - вывести ошибку
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cout << "[-] failed to init GLAD" << std::endl;
        return -1;
    }

    // говорим OpenGL размеры окна
    glViewport(0, 0, 800, 600);

    // указываем наш коллбек
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // render loop
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // закрыть glfw
    glfwTerminate();

    return 0;
}

// реализация коллбека
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}