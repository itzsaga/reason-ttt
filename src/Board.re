open SharedTypes;
open Utils;

let component = ReasonReact.statelessComponent("Board");

let make = (~state: state, ~onMark, ~onRestart, _children) => {
  ...component,
  render: (_) =>
    <div className="game-board">
    </div>
}
