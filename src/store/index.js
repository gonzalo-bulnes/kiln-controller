// Credits: https://github.com/MoonHighway/learning-react/blob/v2.0.0/chapter-09/color-organizer/src/store/index.js

import { createStore, combineReducers, applyMiddleware } from "redux";
import { temperature } from "./reducers";
import { defaultState } from "./data";

const logger = store => next => action => {
  let result;
  console.groupCollapsed("dispatching", action.type);
  console.log("prev state", store.getState());
  console.log("action", action);
  result = next(action);
  console.log("next state", store.getState());
  console.groupEnd();
  return result;
};

const saver = store => next => action => {
  let result = next(action);
  localStorage["redux-store"] = JSON.stringify(store.getState());
  return result;
};

const storeFactory = (initialState = defaultState) =>
  applyMiddleware(logger, saver)(createStore)(
    combineReducers({ temperature }),
    localStorage["redux-store"]
      ? JSON.parse(localStorage["redux-store"])
      : initialState,
    window.__REDUX_DEVTOOLS_EXTENSION__ && window.__REDUX_DEVTOOLS_EXTENSION__()
  );

export default storeFactory;
