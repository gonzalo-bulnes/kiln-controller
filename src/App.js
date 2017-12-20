import React from "react";
import Display from "./Display/Display";

const App = () => (
  <div className="App">
    <Display text="1502°C" />
    <Display text="01:23" />
    <Display text="idle" />
  </div>
);

export default App;
