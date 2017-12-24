import React from "react";
import PropTypes from "prop-types";
import Button from "../Button/Button";
import Display from "../Display/Display";
import { temperatureUnits } from "../../constants";
import "./TemperatureDisplay.css";

export const TemperatureUnit = ({ unit }) => {
  switch (unit) {
    case temperatureUnits.DEG_CELSIUS:
      return (
        <abbr className="unit" title="degrees Celsius">
          °C
        </abbr>
      );
    case temperatureUnits.DEG_FARENHEIT:
      return (
        <abbr className="unit" title="degrees Farenheit">
          °F
        </abbr>
      );
    default:
      return "";
  }
};

const TemperatureDisplay = ({ temperature, unit, toggleUnit }) => (
  <Display>
    {temperature}
    <TemperatureUnit unit={unit} />
    <Button text="Toggle unit" onClick={() => toggleUnit(unit)} />
  </Display>
);

TemperatureDisplay.propTypes = {
  temperature: PropTypes.number.isRequired,
  unit: PropTypes.string
};

export default TemperatureDisplay;
