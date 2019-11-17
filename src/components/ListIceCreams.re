
// open IceCream;
// module ListIceCreams = [%graphql
//   {|
//   query listAll {
//   listIceCreams {
//     items @bsRecord{
//       name
//       description
//       id
//       rating
//     }
//   }
// }
// |}
// ];

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
             | Data(response) => {
              let items = [%get_in response##listIceCreams#??items];
              switch (items) {
               | None => <div> {ReasonReact.string("Nothing to Show")} </div>
               | Some(items) =>
                 let items = items->Belt.Array.keepMap(item => item);
                 <IceCreamList screen="list" items />
               }
             }
         }
      }
    </ListIceCreamsQuery>;
};
