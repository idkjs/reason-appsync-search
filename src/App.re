[%bs.raw {|require('./App.css')|}];

let component = ReasonReact.statelessComponent(__MODULE__);

let make = (~message, _children) => {
  ...component,
  render: _ =>
    <div className="App">
      <div>
        <h2> (ReasonReact.string(message)) </h2>
      </div>
      <p className="App-intro">
        (ReasonReact.string("To get started, edit"))
        <code> (ReasonReact.string(" src/App.re ")) </code>
        (ReasonReact.string("and save to reload."))
      </p>
      <ListIceCreams />
      /* <Search /> */
    </div>,
};
