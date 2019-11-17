module ListIceCreamsQuery =
  ReasonApolloHooks.Query.Make(Queries.ListIceCreams);
[@react.component]
let make = () => {
  let (_simple, full) =
    ListIceCreamsQuery.use(
      ~variables=Queries.ListIceCreams.make()##variables,
      ~notifyOnNetworkStatusChange=true,
      ~fetchPolicy=CacheAndNetwork,
      ~errorPolicy=All,
      (),
    );

  switch (full) {
  | {loading: true, data: None} => React.null
  | {data: Some(data), error, refetch} =>
    // let dataEl = data->Belt.Option.mapWithDefault(React.string("No data"), jsonify);
    let errorEl =
      error->Belt.Option.mapWithDefault(React.null, Utils.jsonify);
    let items =
      Belt.Option.(data##listIceCreams->flatMap(listItems => listItems##items))
      ->Belt.Option.getWithDefault([||])
      ->Belt.Array.keep(Belt.Option.isSome)
      ->Belt.Array.map(Belt.Option.getExn);

    <IceCreamList screen="list with hooks" items />;

  | {error: Some(error)} =>
    <div> {ReasonReact.string(error##message)} </div>
  | {error: None, data: None, loading: false} => React.string("Not asked")
  };
};