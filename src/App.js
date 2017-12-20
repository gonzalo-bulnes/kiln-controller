import React from "react";
import Button from "./Button/Button";
import Display from "./Display/Display";

const App = () => (
  <div className="App">
    <Display text="1502°C" />
    <Display text="01:23" />
    <Display text="idle" />
    <Button
      text="Start"
      onClick={() => console.log("Start button activated")}
    />
    <Button text="Up" onClick={() => console.log("Up button activated")} />
    <Button text="Down" onClick={() => console.log("Down button activated")} />
  </div>
);

export default App;
