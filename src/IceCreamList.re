open IceCream;
open Styles;
let str = ReasonReact.string;
let component = ReasonReact.statelessComponent("VideoGameList");

let make = (~items, _children) => {
  ...component,
  render: _self =>
    <div style=app>
      {items
       /* |> Array.map(iceCreamFromJs) */
       |> Array.map(item =>
            <div key={item.id} style=container>
              <p style=title> {ReasonReact.string(item.name)} </p>
              <p style=title> {ReasonReact.string(item.description)} </p>
            </div>
          )
       |> ReasonReact.array
       }
    </div>,
};