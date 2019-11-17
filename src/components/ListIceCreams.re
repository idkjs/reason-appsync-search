

module ListIceCreamsQuery = ReasonApollo.CreateQuery(Queries.ListIceCreams);

[@react.component]
let make = () => {
    <ListIceCreamsQuery>
      ...{
           ({result}) =>
             switch (result) {
             | Loading => <div> {ReasonReact.string("Searching")} </div>
             | Error(error) =>
               <div> {ReasonReact.string(error##message)} </div>
             | Data(data) => {
               let data =
                 data##listIceCreams
                 ->Belt.Option.flatMap(listItems => listItems##items)
                 ->Belt.Option.getWithDefault([||]);
               Js.log2("data", data);
               let items =
                 data
                 ->Belt.Array.keep(Belt.Option.isSome)
                 ->Belt.Array.map(Belt.Option.getExn);
               <IceCreamList screen="list no hooks" items />;
             }
         }
      }
    </ListIceCreamsQuery>;
};
