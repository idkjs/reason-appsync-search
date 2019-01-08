let app = ReactDOMRe.Style.make(
    ~textAlign="center",
    ()
);
let container = ReactDOMRe.Style.make(
    ~padding="10px",
    ~borderBottom="1px solid #ddd",
    ()
);
let title = ReactDOMRe.Style.make(
    ~fontSize="18px",
    ()
);
let description = ReactDOMRe.Style.make(
    ~fontSize="15px",
    ~color="rgba(0, 0, 0, .5)",
);

let inputStyle =
  ReactDOMRe.Style.make(
    ~height="40px",
    ~width="300px",
    ~padding="7px",
    ~fontSize="15px",
    ~outline="none",
    (),
  );