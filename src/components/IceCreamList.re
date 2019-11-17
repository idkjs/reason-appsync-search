open IceCream;
open Styles;
let str = ReasonReact.string;

[@react.component]
let make = (~items, ~screen) =>
  <div style=app>
    <h1> screen->React.string </h1>
    {items
     |> Array.map(item =>
          <div key={item.id} style=container>
            <p style=title> {ReasonReact.string(item.name)} </p>
            <p style=title> {ReasonReact.string(item.description)} </p>
          </div>
        )
     |> ReasonReact.array}
  </div>;