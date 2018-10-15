
import olc

WHITE = olc.Pixel(255, 255, 255)
GREY = olc.Pixel(192, 192, 192)
DARK_GREY = olc.Pixel(128, 128, 128)
VERY_DARK_GREY = olc.Pixel(64, 64, 64)
RED = olc.Pixel(255, 0, 0)
DARK_RED = olc.Pixel(128, 0, 0)
VERY_DARK_RED = olc.Pixel(64, 0, 0)
YELLOW = olc.Pixel(255, 255, 0)
DARK_YELLOW = olc.Pixel(128, 128, 0)
VERY_DARK_YELLOW = olc.Pixel(64, 64, 0)
GREEN = olc.Pixel(0, 255, 0)
DARK_GREEN = olc.Pixel(0, 128, 0)
VERY_DARK_GREEN = olc.Pixel(0, 64, 0)
CYAN = olc.Pixel(0, 255, 255)
DARK_CYAN = olc.Pixel(0, 128, 128)
VERY_DARK_CYAN = olc.Pixel(0, 64, 64)
BLUE = olc.Pixel(0, 0, 255)
DARK_BLUE = olc.Pixel(0, 0, 128)
VERY_DARK_BLUE = olc.Pixel(0, 0, 64)
MAGENTA = olc.Pixel(255, 0, 255)
DARK_MAGENTA = olc.Pixel(128, 0, 128)
VERY_DARK_MAGENTA = olc.Pixel(64, 0, 64)
BLACK = olc.Pixel(0, 0, 0)
BLANK = olc.Pixel(0, 0, 0, 0)


class Example(olc.PixelGameEngine):
    def __init__(self):
        olc.PixelGameEngine.__init__(self)
        self.sAppName = "Python example"

    def OnUserCreate(self):
        return True

    def OnUserUpdate(self, fElapsedTime):
        self.DrawCircle(50, 50, 25, RED)
        self.DrawString(50, 50, "This is awesome", BLUE)
        return True


example = Example()
if example.Construct(256, 240, 4, 4):
    started = example.Start()
