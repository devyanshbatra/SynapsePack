class SmartBackpackAI:
    def __init__(self, temperature, humidity, air_quality, water_detected):
        self.temperature = temperature  
        self.humidity = humidity        
        self.air_quality = air_quality  
        self.water_detected = water_detected  

    def make_decision(self):
        decisions = []

        if self.temperature < 15:
            decisions.append("Activate heating pad")
        else:
            decisions.append("Heating pad not needed")


        if self.air_quality > 70:
            decisions.append("Poor air quality! Open backpack or relocate.")
        else:
            decisions.append("Air quality is good")

        if self.water_detected:
            decisions.append("Water leakage detected! Remove electronics immediately.")
        else:
            decisions.append("No water leakage")

        if self.humidity > 80:
            decisions.append("High humidity inside backpack, consider ventilation")

        return decisions


if __name__ == "__main__":
    ai = SmartBackpackAI(temperature=12, humidity=85, air_quality=75, water_detected=True)
    decisions = ai.make_decision()
    for d in decisions:
        print("[AI Decision]", d)
