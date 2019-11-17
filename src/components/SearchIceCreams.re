module SearchQuery = ReasonApollo.CreateQuery(Queries.SearchIceCreams);

[@react.component]
let make = (~searchQuery) => {
  let searchQuery = Queries.SearchIceCreams.make(~searchQuery, ());
  <SearchQuery variables=searchQuery##variables>
    ...{({result}) =>
      switch (result) {
      | Loading => <div> {ReasonReact.string("Searching")} </div>
      | Error(error) => <div> {ReasonReact.string(error##message)} </div>
      | Data(data) =>
          // ->Belt.Option.getWithDefault([||])
          /* need to resolve the first option in the returned type by calling `Belt.Array.keep(Belt.Option.isSome)
                    ->Belt.Array.map(Belt.Option.getExn);`
               The type is
               ```
               option(
                 Js.Array.t(
                   option(
                     Js.t(
                       < description : string; id : string; name : string; rating : float option >
                     )
                   )
               ```
             */
        let items =
          Belt.Option.(
            data##listIceCreams->flatMap(listItems => listItems##items)
          )
          ->Belt.Option.getWithDefault([||]);

        let items =
          items
          ->Belt.Array.keep(Belt.Option.isSome)
          ->Belt.Array.map(Belt.Option.getExn);
        // ->Belt.Array.map(makeIceCream);

        <IceCreamList screen="search no hooks" items />;

      }
    }
  </SearchQuery>;
};