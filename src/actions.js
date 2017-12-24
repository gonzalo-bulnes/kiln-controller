import actions from "./constants";

export const setTemperatureUnit = unit => ({
  type: actions.SET_TEMPERATURE_UNIT,
  unit: unit
});
