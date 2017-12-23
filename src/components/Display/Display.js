import React, { Component } from "react";
import "./Display.css";

class Display extends Component {
  render() {
    return <p className="Display">{this.props.children}</p>;
  }
}

export default Display;
