import { connect } from "react-redux";
import { setTemperatureUnit } from "../../actions";
import { temperatureUnits } from "../../constants";
import TemperatureDisplay from "../../components/TemperatureDisplay/TemperatureDisplay";

const celsiusToFarenheit = celsius => Math.floor((celsius - 32) * 1.8);

const mapStateToProps = state => ({
  temperature:
    state.temperature.unit === "DEG_CELSIUS"
      ? state.temperature.value
      : celsiusToFarenheit(state.temperature.value),
  unit: state.temperature.unit
});

const mapDispatchToProps = dispatch => ({
  toggleUnit(unit) {
    unit === temperatureUnits.DEG_CELSIUS
      ? dispatch(setTemperatureUnit(temperatureUnits.DEG_FARENHEIT))
      : dispatch(setTemperatureUnit(temperatureUnits.DEG_CELSIUS));
  }
});

export const Temperature = connect(mapStateToProps, mapDispatchToProps)(
  TemperatureDisplay
);
