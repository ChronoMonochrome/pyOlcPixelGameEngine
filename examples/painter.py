import olc
import random
from os import path
from PIL import Image


class Paint(olc.PixelGameEngine):
    def __init__(self):
        olc.PixelGameEngine.__init__(self)
        self.sAppName = "|| {} ||".format(path.basename(__file__))
        self._paintColor = olc.Pixel.WHITE
        self._clearColor = olc.Pixel.BLANK
        self._brushRadius = 3

    def OnUserCreate(self):
        self.Clear(self._clearColor)
        self._paintColor = olc.Pixel(random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
        return True

    def SaveFrame(self, _name = "saved"):
        t = self.GetDrawTarget()
        img = Image.new("RGBA", (self.ScreenWidth(), self.ScreenHeight()), "black")
        pixels = img.load()
        for i in range(img.size[0]):
            for j in range(img.size[1]):
                pixel = t.GetPixel(i, j)
                pixels[i, j] = (pixel.r, pixel.g, pixel.b, pixel.a)
        img.save("{}.png".format(_name))

    def OnUserUpdate(self, fElapsedTime):
        lmb = self.GetMouse()
        rmb = self.GetMouse(1)
        mmb = self.GetMouse(2)
        space = self.GetKey(olc.Key.SPACE)
        s = self.GetKey(olc.Key.S)

        x = self.GetMouseX()
        y = self.GetMouseY()

        if s.bPressed:
            self.SaveFrame()

        if mmb.bPressed:
            self._paintColor = olc.Pixel(random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))

        if space.bPressed:
            self.Clear(self._clearColor)

        if lmb.bHeld:
            self.FillCircle(x, y, self._brushRadius, self._paintColor)

        if rmb.bHeld:
            self.FillCircle(x, y, self._brushRadius, self._clearColor)

        return True

    @staticmethod
    def run():
        n = Paint()
        if n.Construct(256, 256, 4, 4):
            started = n.Start()


if __name__ == '__main__':
	Paint.run()