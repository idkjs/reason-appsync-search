open Styles;

[@react.component]
let make = (~initialValue, ~onChange=_ => ()) =>
  <div>
    <input
      style=inputStyle
      placeholder="Search for ice cream"
      value=initialValue
      onChange={
        e => {
          let value = ReactEvent.Form.target(e)##value;
          onChange(value);
        }
      }
    />
  </div>;