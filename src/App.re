[%bs.raw {|require('./styles/App.css')|}];

type state = {search: string};

type actions =
  | ChangeSearch(string);

let reducer = (_state, action) =>
  switch (action) {
  | ChangeSearch(newValue) => {search: newValue->String.lowercase}
  };
/* Here we have to pass an empty string with a space bewteen the parens. "" will through a graphql error that string can not be empty. */
let initialState = {search: ""};
[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  let changeSearch = _ => {
    open Utils.Debounce;
    let update =
      make(newValue => dispatch(ChangeSearch(newValue)), ~wait=250);
    newValue => update |> call(newValue);
  };
  <div className="App">
    <Search initialValue=state.search onChange={changeSearch()}/>

    {
      switch (state.search) {
      | "" => <ListIceCreams />
      | search => <SearchIceCreams searchQuery=search />
      }
    }
  </div>;
};