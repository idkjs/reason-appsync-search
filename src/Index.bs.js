// Generated by BUCKLESCRIPT VERSION 4.0.17, PLEASE EDIT WITH CARE
'use strict';

var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var ApolloProvider = require("reason-apollo/src/ApolloProvider.bs.js");
var App$ReactTemplate = require("./App.bs.js");
var Client$ReactTemplate = require("./AWS/Client.bs.js");

ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, ApolloProvider.make(Client$ReactTemplate.instance, /* array */[ReasonReact.element(undefined, undefined, App$ReactTemplate.make(/* array */[]))])), "root");

var match = module.hot;

if (match == null) {
  console.log("We are not hot");
} else {
  match.accept();
}

/*  Not a pure module */
