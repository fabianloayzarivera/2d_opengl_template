#ifdef _MSC_VER
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#define LITE_GFX_IMPLEMENTATION
#include <litegfx.h>
#include <glfw3.h>
#include <iostream>

using namespace std;

int main() {
	// Inicializamos GLFW
	if (!glfwInit()) {
		cout << "Error: No se ha podido inicializar GLFW" << endl;
		return -1;
	}
	atexit(glfwTerminate);

	// Creamos la ventana
	glfwWindowHint(GLFW_RESIZABLE, false);
	GLFWwindow* window = glfwCreateWindow(800, 600, "2D OpenGL", nullptr, nullptr);
	if (!window) {
		cout << "Error: No se ha podido crear la ventana" << endl;
		return -1;
	}

	// Activamos contexto de OpenGL
	glfwMakeContextCurrent(window);

	// Inicializamos LiteGFX
	lgfx_setup2d(800, 600);

	// Bucle principal
	float x = 0;
	double lastTime = glfwGetTime();
	while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE)) {
		// Actualizamos delta
		float deltaTime = static_cast<float>(glfwGetTime() - lastTime);
		lastTime = glfwGetTime();

		// Actualizamos tamaño de ventana
		int screenWidth, screenHeight;
		glfwGetWindowSize(window, &screenWidth, &screenHeight);
		lgfx_setviewport(0, 0, screenWidth, screenHeight);

		// Actualizacion de logica del programa
		x += 128 * deltaTime;

		// Pintado
		lgfx_clearcolorbuffer(0, 0, 0.5f);
		lgfx_setcolor(1, 0, 0, 1);
		lgfx_drawrect(x, screenHeight/2 - 50, 100, 100);

		// Actualizamos ventana y eventos
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    return 0;
}
