import React from "react";
import Enzyme, { mount, shallow } from "enzyme";
import Adapter from "enzyme-adapter-react-16";
import { temperatureUnits } from "../../constants";
import TemperatureDisplay from "./TemperatureDisplay";

Enzyme.configure({ adapter: new Adapter() });

describe("TemperatureDisplay", () => {
  it("renders a Display", () => {
    expect(
      shallow(<TemperatureDisplay temperature={231} />).find("Display").length
    ).toBe(1);
  });

  it("displays temperature", () => {
    expect(mount(<TemperatureDisplay temperature={1234} />).text()).toContain(
      "1234"
    );
  });

  describe("when a temperature unit is provided", () => {
    it("displays temperature unit (°C)", () => {
      expect(
        mount(
          <TemperatureDisplay
            temperature={1503}
            unit={temperatureUnits.DEG_CELSIUS}
          />
        ).text()
      ).toContain("°C");
    });

    it("displays temperature unit (°F)", () => {
      expect(
        mount(
          <TemperatureDisplay
            temperature={1503}
            unit={temperatureUnits.DEG_FARENHEIT}
          />
        ).text()
      ).toContain("°F");
    });
  });
});
