import React from "react";
import PropTypes from "prop-types";
import Display from "../Display/Display";

const prefix = number => {
  return number < 10 ? `0${number}` : `${number}`;
};

const TimeDisplay = ({ hours, minutes }) => (
  <Display>
    {prefix(hours)}:{prefix(minutes)}
  </Display>
);

TimeDisplay.propTypes = {
  hours: PropTypes.number,
  minutes: PropTypes.number
};

export default TimeDisplay;
