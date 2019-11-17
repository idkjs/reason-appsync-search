module SearchQuery = ReasonApolloHooks.Query.Make(Queries.SearchIceCreams);

[@react.component]
let make = (~searchQuery, ()) => {
  let (_simple, full) =
    SearchQuery.use(
      ~variables=Queries.SearchIceCreams.make(~searchQuery, ())##variables,
      ~notifyOnNetworkStatusChange=true,
      (),
    );

  switch (full) {
  | {loading: true, data: None} => React.null
  | {data: Some(data)} =>
    let items =
      Belt.Option.(data##listIceCreams->flatMap(listItems => listItems##items))
      ->Belt.Option.getWithDefault([||])
      ->Belt.Array.keep(Belt.Option.isSome)
      ->Belt.Array.map(Belt.Option.getExn);

    <IceCreamList screen="search with hooks" items />;
  | {error: Some(error)} =>
    <div> {ReasonReact.string(error##message)} </div>
  | {error: None, data: None, loading: false} => React.string("Not asked")
  };
};