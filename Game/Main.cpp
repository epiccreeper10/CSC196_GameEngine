#include "Core/Memory.h"
#include <iostream>
#include "Math/MathUtils.h"
#include "Renderer/Renderer.h"
#include "Math/Random.h"
#include <vector>


using namespace std;
	
template <typename T>
class smart_ptr
{
public:
	smart_ptr(T* ptr) : ptr{ ptr } {}
	~smart_ptr() { delete ptr; }
private:
	T* ptr;
};
	int main()
	{
		neu::SeedRandom(23443);
		for (int i = 0; i < 10; i++) {
			cout << neu::randomf(5,10) << endl;
		}



		neu::InitializeMemory();
		neu::Renderer renderer;
		renderer.Initialize();
		renderer.CreateWindow("Neumont", 800, 600);

		while (1) 
		{

			//renderer.BeginFrame();
			// draw
			renderer.DrawLine(neu::randomf(800), neu::randomf(600), neu::randomf(800), neu::randomf(600));
			renderer.DrawPoint(neu::randomf(800), neu::randomf(600));
			renderer.EndFrame();
		}

		getchar();
	}
	