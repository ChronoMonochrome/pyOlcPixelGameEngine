
import olc
import random
from os import path


class Noise(olc.PixelGameEngine):
    def __init__(self):
        olc.PixelGameEngine.__init__(self)
        self.sAppName = "|| {} ||".format(path.basename(__file__))
        self._w = 0
        self._h = 0

    def OnUserCreate(self):
        self._w = self.ScreenWidth()
        self._h = self.ScreenHeight()
        return True

    def OnUserUpdate(self, fElapsedTime):
        [self.Draw(x, y, olc.Pixel(random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))) for x in range(self._w) for y in range(self._h)]
        return True

    @staticmethod
    def run():
        n = Noise()
        if n.Construct(64, 64, 8, 8):
            started = n.Start()


if __name__ == '__main__':
	Noise.run()
