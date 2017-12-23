import React from "react";
import PropTypes from "prop-types";
import Display from "../Display/Display";
import "./TemperatureDisplay.css";

export const DEG_CELSIUS = "DEG_CELSIUS";
export const DEG_FARENHEIT = "DEG_FARENHEIT";

export const TemperatureUnit = ({ unit }) => {
  switch (unit) {
    case DEG_CELSIUS:
      return (
        <abbr className="unit" title="degrees Celsius">
          °C
        </abbr>
      );
    case DEG_FARENHEIT:
      return (
        <abbr className="unit" title="degrees Farenheit">
          °F
        </abbr>
      );
    default:
      return "";
  }
};

const TemperatureDisplay = ({ temperature, unit }) => (
  <Display>
    {temperature}
    <TemperatureUnit unit={unit} />
  </Display>
);

TemperatureDisplay.propTypes = {
  temperature: PropTypes.number.isRequired,
  unit: PropTypes.string
};

export default TemperatureDisplay;
