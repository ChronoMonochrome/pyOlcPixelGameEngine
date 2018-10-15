import olc
import random
from os import path
from definitions import *

class Noise(olc.PixelGameEngine):
    def __init__(self):
        olc.PixelGameEngine.__init__(self)
        self.sAppName = "|| {} ||".format(path.basename(__file__))

    def OnUserCreate(self):
        return True

    def OnUserUpdate(self, fElapsedTime):
        for x in range(self.ScreenWidth()):
            for y in range(self.ScreenHeight()):
                self.Draw(x, y, olc.Pixel(random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)))
        self.DrawString(4, int(self.ScreenHeight() / 4), "This is\nawesome", BLUE, 1)
        return True

    @staticmethod
    def run():
        n = Noise()
        if n.Construct(64, 64, 8, 8):
            started = n.Start()
