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
let input = ReactDOMRe.Style.make(
    ~height="40px",
    ~width="300px",
    ~padding="7px",
    ~fontSize="15px",
    ~outline="none",
    ()
);
open IceCream;
module Search = [%graphql
  {|
  query($searchQuery: String) {
    listIceCreams(filter: {
      searchField: {
        contains: $searchQuery
      }
    }) {
      items @bsRecord{
        id
        name
        description
        rating
      }
    }
  }
|}
];

module SearchQuery = ReasonApollo.CreateQuery(Search);

let component = ReasonReact.statelessComponent("Search");

let make = (_children) => {
  ...component,
  render: _ => {
    let searchQuery = Search.make(~searchQuery="", ());
    <SearchQuery variables=searchQuery##variables>
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
                 <div>
                 <ul>
                { items
                 |> Array.map(item =>
                      <li key={item.id}>
                        <p> {ReasonReact.string(item.name)} </p>
                      </li>
                      )
                 |> ReasonReact.array
                 }
                 </ul>

                 </div>
               }
             }
         }
      }
    </SearchQuery>;
  },
};
 /*| Some(items) =>
                 let items = items->Belt.Array.keepMap(item => item);
                 items


               <div> {
                /* Handles a deeply nested optional response */
                {ReasonReact.string("Data Logged?")}
                response##listIceCreams

                /* response##data
                -> Belt.Option.flatMap(user => user##device)
                -> Belt.Option.flatMap(device => device##brand)
                -> Belt.Option.mapWithDefault("", brand => brand##name) */
               } </div> */
               /* } */