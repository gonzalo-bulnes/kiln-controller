import React from "react";
import ReactDOM from "react-dom";
import { Provider } from "react-redux";
import storeFactory from "./store";
import App from "./App";

describe("App", () => {
  let store;

  beforeAll(() => {
    store = storeFactory({});
  });

  it("renders without crashing", () => {
    const div = document.createElement("div");
    ReactDOM.render(
      <Provider store={store}>
        <App />
      </Provider>,
      div
    );
  });
});
