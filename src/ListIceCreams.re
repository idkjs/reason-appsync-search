
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
                 <IceCreamList items />

                 /* <div style=app>
                { items
                 |> Array.map(item =>
                      <div key={item.id} style=container>
                        <p style=title> {ReasonReact.string(item.name)} </p>
                        <p style=title> {ReasonReact.string(item.description)} </p>
                      </div>
                      )
                 |> ReasonReact.array
                 }
                 </div> */
               }
             }
         }
      }
    </ListIceCreamsQuery>;
  },
};
