type debounceOptions = {
  .
  "leading": bool,
  "maxWait": int,
  "trailing": bool
};

module Debounce = {
  [@bs.module]
  external _make :
    ('fArgs => 'fOutput, int, debounceOptions) => [@bs] ('fArgs => 'fOutput) =
    "lodash.debounce";
  let make = (~wait=0, ~options=Js.Obj.empty(), f) => _make(f, wait, options);
  let call = (input, f) => [@bs] f(input);
};

/* A helper for pretty-stringifying results
   https://github.com/dangdennis/reasonconf-reasondojo/blob/master/src/Index.re
   */
[@bs.val]
external prettyStringify: ('a, Js.Nullable.t(unit), int) => string =
  "JSON.stringify";
let jsonify = data =>
  <div>
    <h4 className="card-title"> {React.string("Raw Response")} </h4>
    <pre> {React.string(prettyStringify(data, Js.Nullable.null, 2))} </pre>
  </div>;

let getInputValue = (e): string => ReactEvent.Form.target(e)##value;