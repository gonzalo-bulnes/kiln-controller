import React from "react";
import Button from "./Button/Button";
import Display from "./Display/Display";
import TemperatureDisplay, {
  DEG_CELSIUS,
  DEG_FARENHEIT
} from "./TemperatureDisplay/TemperatureDisplay";
import TimeDisplay from "./TimeDisplay/TimeDisplay";

const App = () => (
  <div className="App">
    <TemperatureDisplay temperature={1502} unit={DEG_CELSIUS} />
    <TimeDisplay hours={1} minutes={3} />
    <Display>idle</Display>
    <TemperatureDisplay temperature={1560} unit={DEG_FARENHEIT} />
    <Button
      text="Start"
      onClick={() => console.log("Start button activated")}
    />
    <Button text="Up" onClick={() => console.log("Up button activated")} />
    <Button text="Down" onClick={() => console.log("Down button activated")} />
  </div>
);

export default App;
