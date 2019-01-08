let app = ReactDOMRe.Style.make(
    ~textAlign="center",
    ()
);
let container = ReactDOMRe.Style.make(
    ~padding="10px",
    ~borderBottom="1px solid #ddd",
    ()
);
let title = ReactDOMRe.Style.make(
    ~fontSize="18px",
    ()
);
let description = ReactDOMRe.Style.make(
    ~fontSize="15px",
    ~color="rgba(0, 0, 0, .5)",
);
let inputStyle = ReactDOMRe.Style.make(
    ~height="40px",
    ~width="300px",
    ~padding="7px",
    ~fontSize="15px",
    ~outline="none",
    ()
);
open IceCream;
module ListIceCreams = [%graphql
  {|
  query listAll {
  listIceCreams {
    items @bsRecord{
      name
      description
      id
      rating
    }
  }
}
|}
];

module ListIceCreamsQuery = ReasonApollo.CreateQuery(ListIceCreams);

let component = ReasonReact.statelessComponent("ListIceCreams");

let make = (_children) => {
  ...component,
  render: _ => {
    /* let listIceCreamsQuery = ListIceCreams.make(()); */
    <ListIceCreamsQuery>
      ...{
           ({result}) =>
             switch (result) {
             | Loading => <div> {ReasonReact.string("Searching")} </div>
             | Error(error) =>
               <div> {ReasonReact.string(error##message)} </div>
             | Data(response) => {
              let items = [%get_in response##listIceCreams#??items];
              switch (items) {
               | None => <div> {ReasonReact.string("Nothing to Show")} </div>
               | Some(items) =>
                 let items = items->Belt.Array.keepMap(item => item);

                 <div style=app>
                <div> {ReasonReact.string("SearchBox")} </div>
                { items
                 |> Array.map(item =>
                      <div key={item.id} style=container>
                        <p style=title> {ReasonReact.string(item.name)} </p>
                        <p style=title> {ReasonReact.string(item.description)} </p>
                      </div>
                      )
                 |> ReasonReact.array
                 }
                 </div>
               }
             }
         }
      }
    </ListIceCreamsQuery>;
  },
};
