open Styles;

type state = {value: string};

type action =
  | ChangeValue(string);

let component = ReasonReact.reducerComponent("Search");

let reducer = (action, _state) =>
  switch (action) {
  | ChangeValue(newValue) => ReasonReact.Update({value: newValue})
  };

let make = (~initialValue="", ~onChange=_newValue => (), _children) => {
  ...component,
  initialState: () => {value: initialValue},
  reducer,
  render: ({send, state}) =>
    <div>
      <input
        style=inputStyle
        placeholder="Search for ice cream"
        value={state.value}
        onChange={e => {
          let value = ReactEvent.Form.target(e)##value;
          send(ChangeValue(value));
          onChange(value);
        }}
      />
    </div>,
};