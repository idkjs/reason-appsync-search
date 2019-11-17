open Config;
/* Create an HTTP Link */
let httpLink = ApolloLinks.createHttpLink(~uri=config.graphqlEndpoint, ());

/* create the authLinkOption object to pass to authLink */
let auth =
  AwsAppSync.AuthLink.authLinkOptions(
    ~type_=config.authenticationType,
    ~apiKey=config.apiKey,
  );

/* create our authLink required to connect appsync to reason-apollo */
let authLink =
  AwsAppSync.AuthLink.(
    createAuthLink(
      authLink(~url=config.graphqlEndpoint, ~region=config.region, ~auth, ()),
    )
  );

/* create our subcriptionLinkOptions required to connect appsync to reason-apollo */
let subcriptionLinkOptions =
  AwsAppSync.SubscriptionLink.(
    subscriptionLink(~url=config.graphqlEndpoint, ~httpLink, ())
  );
/* pass subcriptionLinkOptions to createSubscriptionHandshakeLink from AwsAppSync  */
let subcriptionLink =
  AwsAppSync.SubscriptionLink.(createSubscriptionHandshakeLink(
    subcriptionLinkOptions,
  ));

/* create an array of authLinks to pass to client instance */
let link = ApolloLinks.from([|authLink, httpLink|]);

/* Create an InMemoryCache to pass to client instance*/
let cache = ApolloInMemoryCache.createInMemoryCache();

/* Create an ApolloClient instance*/
let instance = ReasonApollo.createApolloClient(~link, ~cache, ());