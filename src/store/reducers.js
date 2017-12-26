import actions from "../constants";

export const temperature = (state = {}, action) => {
  switch (action.type) {
    case actions.SET_TEMPERATURE_UNIT:
      return {
        ...state,
        unit: action.unit
      };
    default:
      return state;
  }
};
