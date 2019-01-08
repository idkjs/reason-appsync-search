[%bs.raw {|require('./App.css')|}];

type state = {search: string};

type actions =
  | ChangeSearch(string);

let changeSearch = send => {
  open Utils.Debounce;
  let update = make(newValue => send(ChangeSearch(newValue)), ~wait=250);
  newValue => update |> call(newValue);
};

let reducer = (action, _state) =>
  switch action {
  | ChangeSearch(newValue) => ReasonReact.Update({search: (newValue->String.lowercase)})
  };

let initialState = () => {search: ""};
let component = ReasonReact.reducerComponent(__MODULE__);

let make = (_children) => {
  ...component,
  initialState,
  reducer,
  render:({state,send}) =>
    <div className="App">
      <Search onChange=(changeSearch(send)) />
      {
        switch(state.search){
        | ("") => <ListIceCreams />
        | (search) => <SearchIceCreams searchQuery=search />
        }
      }
    </div>,
};
