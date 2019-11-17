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

module SearchIceCreams = [%graphql
  {|
  query($searchQuery: String) {
    listIceCreams(filter: {
      description: {
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