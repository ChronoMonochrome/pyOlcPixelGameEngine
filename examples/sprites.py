
import olc
import random
from os import path


class Sprites(olc.PixelGameEngine):
    def __init__(self):
        olc.PixelGameEngine.__init__(self)
        self.sAppName = "|| {} ||".format(path.basename(__file__))
        self._s = None

    def OnUserCreate(self):
        self._s = olc.Sprite("resources/s1.png")
        return True

    def OnUserUpdate(self, fElapsedTime):
        self.DrawSprite(0, 0, self._s)
        return True

    @staticmethod
    def run():
        n = Sprites()
        if n.Construct(128, 128, 8, 8):
            started = n.Start()


if __name__ == "__main__":
    Sprites.run()
