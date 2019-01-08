// Generated by BUCKLESCRIPT VERSION 4.0.17, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Styles$ReactTemplate = require("./Styles.bs.js");

function str(prim) {
  return prim;
}

var component = ReasonReact.statelessComponent("VideoGameList");

function make(items, _children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              return React.createElement("div", {
                          style: Styles$ReactTemplate.app
                        }, $$Array.map((function (item) {
                                return React.createElement("div", {
                                            key: item[/* id */0],
                                            style: Styles$ReactTemplate.container
                                          }, React.createElement("p", {
                                                style: Styles$ReactTemplate.title
                                              }, item[/* name */1]), React.createElement("p", {
                                                style: Styles$ReactTemplate.title
                                              }, item[/* description */2]));
                              }), items));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.str = str;
exports.component = component;
exports.make = make;
/* component Not a pure module */
