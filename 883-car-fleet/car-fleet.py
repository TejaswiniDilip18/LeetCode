class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair = [[p, s] for p,s in zip(position, speed)]
        lastCar = 0
        fleets = 0

        for [p,s] in sorted(pair, reverse=True):
            time = (target - p)/s
            if(time > lastCar):
                fleets += 1
                lastCar = time

        return fleets