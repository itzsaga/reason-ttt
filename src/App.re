[%bs.raw {|require('./App.css')|}];

[@bs.module] external logo : string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");
let make = _children => {
  ...component,
  render: _self =>
    <div>
      <div className="title">
        (ReasonReact.stringToElement("Tic Tac Toe"))
      </div>
      <Game />
    </div>,
};
