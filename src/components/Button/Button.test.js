import React from "react";
import Enzyme, { shallow } from "enzyme";
import Adapter from "enzyme-adapter-react-16";
import Button from "./Button";

Enzyme.configure({ adapter: new Adapter() });

describe("Button", () => {
  it("renders a button", () => {
    expect(shallow(<Button />).find("button").length).toBe(1);
  });

  it("displays text", () => {
    expect(shallow(<Button text="Example" />).text()).toContain("Example");
  });

  it("invokes onClick", () => {
    const _click = jest.fn();
    shallow(<Button onClick={_click} />)
      .find("button")
      .simulate("click");
    expect(_click).toBeCalled();
  });
});
