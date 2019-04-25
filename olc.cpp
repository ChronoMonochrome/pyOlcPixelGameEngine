#include "pybind11/pybind11.h"

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

namespace py = pybind11;


class PyPixelGameEngine : public olc::PixelGameEngine
{
public:
	using olc::PixelGameEngine::PixelGameEngine;

	bool OnUserCreate() override
	{
		PYBIND11_OVERLOAD(
			bool,
			olc::PixelGameEngine,
			OnUserCreate,
		);
	};

	bool OnUserUpdate(float fElapsedTime) override
	{
		PYBIND11_OVERLOAD(
			bool,
			olc::PixelGameEngine,
			OnUserUpdate,
			fElapsedTime
		);
	}

	bool OnUserDestroy() override
	{
		PYBIND11_OVERLOAD(
			bool,
			olc::PixelGameEngine,
			OnUserDestroy,
		);
	}

	bool Draw(int32_t x, int32_t y, olc::Pixel p /* = olc::WHITE */) override
	{
		PYBIND11_OVERLOAD(
			bool,
			olc::PixelGameEngine,
			Draw,
			x,
			y,
			p
		);
	}
};


PYBIND11_MODULE(olc, m)
{
	m.doc() = "Python bindings for olcPixelGameEngine";

	//////////////////////////// Pixel ///////////////////////////////////////////
	py::class_<olc::Pixel> pixel(m, "Pixel");

	pixel.def(py::init<>())
		.def(py::init<uint8_t, uint8_t, uint8_t, uint8_t>(),
			py::arg("red") = 0,
			py::arg("green") = 0,
			py::arg("blue") = 0,
			py::arg("alpha") = 255)
		.def_readwrite("r", &olc::Pixel::r)
		.def_readwrite("g", &olc::Pixel::g)
		.def_readwrite("b", &olc::Pixel::b)
		.def_readwrite("a", &olc::Pixel::a);

	py::enum_<olc::Pixel::Mode>(pixel, "Mode")
		.value("ALPHA", olc::Pixel::Mode::ALPHA)
		.value("MASK", olc::Pixel::Mode::MASK)
		.value("NORMAL", olc::Pixel::Mode::NORMAL)
		.export_values();

	pixel.def("__repr__", [](const olc::Pixel &p)
	{
		std::string result = "<Pixel> (r:" + std::to_string(p.r) + " g:" + std::to_string(p.g) + " b:" + std::to_string(p.b) + " a:" + std::to_string(p.a) + ")";

		return result;
	});
	//////////////////////////// Pixel ///////////////////////////////////////////


	//////////////////////////// rcode ///////////////////////////////////////////
	py::enum_<olc::rcode>(m, "rcode")
		.value("FAIL", olc::rcode::FAIL)
		.value("NO_FILE", olc::rcode::NO_FILE)
		.value("OK", olc::rcode::OK)
		.export_values();
	//////////////////////////// rcode ///////////////////////////////////////////

	//////////////////////////// HWButton ///////////////////////////////////////////
	py::class_<olc::HWButton>(m, "HWButton")
		.def_readwrite("bHeld", &olc::HWButton::bHeld)
		.def_readwrite("bPressed", &olc::HWButton::bPressed)
		.def_readwrite("bReleased", &olc::HWButton::bReleased)
		.def("__repr__", [](const olc::HWButton &b)
	{
		std::string result = "Held: " + std::to_string(b.bHeld) + " Pressed: " + std::to_string(b.bPressed) + " Released: " + std::to_string(b.bReleased);
		return result;
	});
	//////////////////////////// HWButton ///////////////////////////////////////////

	//////////////////////////// Sprite ///////////////////////////////////////////
	py::class_<olc::Sprite> sprite(m, "Sprite");
	sprite.def(py::init<>())
		.def(py::init<std::string>())
		.def(py::init<int32_t, int32_t >());

	py::enum_<olc::Sprite::Mode>(sprite, "Mode")
		.value("NORMAL", olc::Sprite::NORMAL)
		.value("PERIODIC", olc::Sprite::PERIODIC)
		.export_values();

	sprite.def("LoadFromFile", &olc::Sprite::LoadFromFile)
		.def("LoadFromSprFile", &olc::Sprite::LoadFromPGESprFile)
		.def_readwrite("width", &olc::Sprite::width)
		.def_readwrite("height", &olc::Sprite::height)
		.def("GetPixel", &olc::Sprite::GetPixel)
		.def("SetPixel", &olc::Sprite::SetPixel)
		.def("Sample", &olc::Sprite::Sample)
		.def("SampleBL", &olc::Sprite::SampleBL)
		.def("GetData", &olc::Sprite::GetData, py::return_value_policy::reference)
		.def("SetSampleMode", &olc::Sprite::SetSampleMode)
		;

	//////////////////////////// Sprite ///////////////////////////////////////////

	//////////////////////////// Key ///////////////////////////////////////////
	py::enum_<olc::Key>(m, "Key")
		.value("A", olc::Key::A).value("B", olc::Key::B).value("C", olc::Key::C).value("D", olc::Key::D)
		.value("E", olc::Key::E).value("F", olc::Key::F).value("G", olc::Key::G).value("H", olc::Key::H)
		.value("I", olc::Key::I).value("J", olc::Key::J).value("K", olc::Key::K).value("L", olc::Key::L)
		.value("M", olc::Key::M).value("N", olc::Key::N).value("O", olc::Key::O).value("P", olc::Key::P)
		.value("Q", olc::Key::Q).value("R", olc::Key::R).value("S", olc::Key::S).value("T", olc::Key::T)
		.value("U", olc::Key::U).value("V", olc::Key::V).value("W", olc::Key::W).value("X", olc::Key::X)
		.value("Y", olc::Key::Y).value("Z", olc::Key::Z).value("K0", olc::Key::K0).value("K1", olc::Key::K1)
		.value("K2", olc::Key::K2).value("K3", olc::Key::K3).value("K4", olc::Key::K4).value("K5", olc::Key::K5)
		.value("K6", olc::Key::K6).value("K7", olc::Key::K7).value("K8", olc::Key::K8).value("K9", olc::Key::K9)
		.value("F1", olc::Key::F1).value("F2", olc::Key::F2).value("F3", olc::Key::F3).value("F4", olc::Key::F4)
		.value("F5", olc::Key::F5).value("F6", olc::Key::F6).value("F7", olc::Key::F7).value("F8", olc::Key::F8)
		.value("F9", olc::Key::F9).value("F10", olc::Key::F10).value("F11", olc::Key::F11).value("F12", olc::Key::F12)
		.value("UP", olc::Key::UP).value("DOWN", olc::Key::DOWN).value("LEFT", olc::Key::LEFT).value("RIGHT", olc::Key::RIGHT)
		.value("SPACE", olc::Key::SPACE).value("TAB", olc::Key::TAB).value("SHIFT", olc::Key::SHIFT).value("CTRL", olc::Key::CTRL)
		.value("INS", olc::Key::INS).value("DEL", olc::Key::DEL).value("HOME", olc::Key::HOME).value("END", olc::Key::END)
		.value("PGUP", olc::Key::PGUP).value("PGDN", olc::Key::PGDN).value("BACK", olc::Key::BACK).value("ESCAPE", olc::Key::ESCAPE)
		.value("ENTER", olc::Key::ENTER).value("PAUSE", olc::Key::PAUSE).value("SCROLL", olc::Key::SCROLL).export_values();
	//////////////////////////// Key ///////////////////////////////////////////

	//////////////////////////// PixelGameEngine ///////////////////////////////////////////

	py::class_<olc::PixelGameEngine, PyPixelGameEngine> pge(m, "PixelGameEngine");
	pge.def(py::init<>())
		.def_readwrite("sAppName", &olc::PixelGameEngine::sAppName)
		.def("Construct", &olc::PixelGameEngine::Construct,
			py::arg("screen_w") = 256,
			py::arg("screen_h") = 256,
			py::arg("pixel_w") = 1,
			py::arg("pixel_h") = 1,
			py::arg("full_screen") = false)
		.def("Start", &olc::PixelGameEngine::Start, py::call_guard<py::gil_scoped_release>())
		.def("OnUserCreate", &olc::PixelGameEngine::OnUserCreate)
		.def("OnUserUpdate", &olc::PixelGameEngine::OnUserUpdate)
		.def("OnUserDestroy", &olc::PixelGameEngine::OnUserDestroy)
		.def("IsFocused", &olc::PixelGameEngine::IsFocused)
		.def("GetKey", &olc::PixelGameEngine::GetKey)
		.def("GetMouse", &olc::PixelGameEngine::GetMouse, py::arg("b") = 0)
		.def("GetMouseX", &olc::PixelGameEngine::GetMouseX)
		.def("GetMouseY", &olc::PixelGameEngine::GetMouseY)
		.def("ScreenWidth", &olc::PixelGameEngine::ScreenWidth)
		.def("ScreenHeight", &olc::PixelGameEngine::ScreenHeight)
		.def("GetDrawTargetWidth", &olc::PixelGameEngine::GetDrawTargetWidth)
		.def("GetDrawTargetHeight", &olc::PixelGameEngine::GetDrawTargetHeight)
		.def("GetDrawTarget", &olc::PixelGameEngine::GetDrawTarget, py::return_value_policy::reference)
		.def("SetDrawTarget", &olc::PixelGameEngine::SetDrawTarget, py::arg("target") = nullptr)
		.def("SetPixelMode", &olc::PixelGameEngine::SetPixelMode)
		.def("SetPixelBlend", &olc::PixelGameEngine::SetPixelBlend, py::arg("fBlend") = 0.f)
		.def("SetSubPixelOffset", &olc::PixelGameEngine::SetSubPixelOffset,
			py::arg("ox") = 0.f,
			py::arg("oy") = 0.f)
		;

	pge.def("Draw", &olc::PixelGameEngine::Draw)
		.def("DrawLine", &olc::PixelGameEngine::DrawLine,
			py::arg("x1") = 0,
			py::arg("y1") = 0,
			py::arg("x2") = 0,
			py::arg("y2") = 0,
			py::arg("p") = olc::WHITE)
		.def("DrawCircle", &olc::PixelGameEngine::DrawCircle,
			py::arg("x") = 0,
			py::arg("y") = 0,
			py::arg("radius") = 0,
			py::arg("p") = olc::WHITE)
		.def("FillCircle", &olc::PixelGameEngine::FillCircle,
			py::arg("x") = 0,
			py::arg("y") = 0,
			py::arg("radius") = 0,
			py::arg("p") = olc::WHITE)
		.def("DrawRect", &olc::PixelGameEngine::DrawRect,
			py::arg("x") = 0,
			py::arg("y") = 0,
			py::arg("w") = 0,
			py::arg("h") = 0,
			py::arg("p") = olc::WHITE)
		.def("FillRect", &olc::PixelGameEngine::FillRect,
			py::arg("x") = 0,
			py::arg("y") = 0,
			py::arg("w") = 0,
			py::arg("h") = 0,
			py::arg("p") = olc::WHITE)
		.def("DrawTriangle", &olc::PixelGameEngine::DrawTriangle,
			py::arg("x1") = 0,
			py::arg("y1") = 0,
			py::arg("x2") = 0,
			py::arg("y2") = 0,
			py::arg("x3") = 0,
			py::arg("y3") = 0,
			py::arg("p") = olc::WHITE)
		.def("FillTriangle", &olc::PixelGameEngine::FillTriangle,
			py::arg("x1") = 0,
			py::arg("y1") = 0,
			py::arg("x2") = 0,
			py::arg("y2") = 0,
			py::arg("x3") = 0,
			py::arg("y3") = 0,
			py::arg("p") = olc::WHITE)
		.def("DrawSprite", &olc::PixelGameEngine::DrawSprite,
			py::arg("x") = 0,
			py::arg("y") = 0,
			py::arg("Sprite") = nullptr,
			py::arg("scale") = 1)
		.def("DrawPartialSprite", &olc::PixelGameEngine::DrawPartialSprite,
			py::arg("x") = 0,
			py::arg("y") = 0,
			py::arg("Sprite") = nullptr,
			py::arg("ox") = 1,
			py::arg("oy") = 1,
			py::arg("w") = 1, 
			py::arg("h") = 1,
			py::arg("scale") = 1)
		.def("DrawString", &olc::PixelGameEngine::DrawString,
			py::arg("x") = 0,
			py::arg("y") = 0,
			py::arg("sText") = "Text",
			py::arg("col") = olc::WHITE,
			py::arg("scale") = 1)
		.def("Clear", &olc::PixelGameEngine::Clear, py::arg("p") = olc::BLACK);

	//////////////////////////// PixelGameEngine ///////////////////////////////////////////

}
