// /**
//  * @type {string[]}
//  **/
// const delimiters = ["&", "="];

// /**
//  * @param {string} _input
//  * @returns {Output[]}
//  **/
// const parseString = (_input) => {
//   const split_input = input.trim().split(delimiters[0]);

//   /**
//    * @typedef {Object} Output
//    * @property {string} key
//    * @property {string} value
//    **/

//   /**
//    * @type {Output[]}
//    **/
//   let output = [];

//   split_input.forEach((_e) => {
//     const _initial = _e.split(delimiters[1]);
//     const [key, value] = _initial;
//     if (!key || !value) return;

//     output.push({ [key]: value });
//   });

//   return output;
// };

// Optimize

/**
 * @param {string} _input
 * @returns {Array<{ key: string, value: string }>}
 **/
const parseQuery   = (_input) => {
  return _input.trim() === ""
    ? null
    : _input
        .split("&")
        .map((_e) => {
          const [key, value] = _e.split("=");
          return { key, value };
        })
        .filter(({ key, value }) => key && value);
};

const input = "";

console.log(parseQuery(input));
