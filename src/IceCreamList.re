open IceCream;

let str = ReasonReact.string;
let component = ReasonReact.statelessComponent("VideoGameList");

let make = (~items, _children) => {
  ...component,
  render: _self =>
      <ul style={ReactDOMRe.Style.make(~listStyleType="none", ())}>
      {
        items
        |> Array.map(iceCreamFromJs)
        |> Array.map(item =>
             <li key={item.id}>
             	{item.name ++ " | " ++ item.description |> str}
             </li>
           )
        |> ReasonReact.array
      }
    </ul>,
};