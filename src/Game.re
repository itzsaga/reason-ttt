open SharedTypes;

let initialState = {
  board: [
    [Empty, Empty, Empty],
    [Empty, Empty, Empty],
    [Empty, Empty, Empty],
  ],
  gameState: Playing(Cross),
}

let component = ReasonReact.reducerComponent("Game");

let make = _children => {
  ...component,
  initialState = () => initialState,
  reducer: (action: action, state: state) =>
    switch (action) {
    | Restart => ReasonReact.Update(initialState),
    | ClickSquare((id: string)) =>
      let updateBoard = updateBoard(state.board, state.gameState, id);
      ReasonReact.Update({
        board: updateBoard,
        gameState: checkGameState3x3(updateBoard, state.board, state.gameState),
      });
    },
  render: ({state, reduce}) =>
    <div className="game">
      <Board
        state
        onRestart=(reduce(_evt => Restart))
        onMark=(reduce(id => ClickSquare(id)))
      />
    </div>,
}
