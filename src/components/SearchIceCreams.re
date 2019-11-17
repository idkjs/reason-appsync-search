module SearchQuery = ReasonApollo.CreateQuery(Queries.SearchIceCreams);

[@react.component]
let make = (~searchQuery) => {
  let searchQuery = Queries.SearchIceCreams.make(~searchQuery, ());
  <SearchQuery variables=searchQuery##variables>
    ...{
         ({result}) =>
           switch (result) {
           | Loading => <div> {ReasonReact.string("Searching")} </div>
           | Error(error) =>
             <div> {ReasonReact.string(error##message)} </div>
           | Data(response) =>
             let items = [%get_in response##listIceCreams#??items];
             switch (items) {
             | None => <div> {ReasonReact.string("Nothing to Show")} </div>
             | Some(items) =>
               let items = items->Belt.Array.keepMap(item => item);
               <IceCreamList screen="search" items />;
             };
           }
       }
  </SearchQuery>;
};