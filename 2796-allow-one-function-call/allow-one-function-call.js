function once(fn) {
  let called = false;

  return function (...args) {
    if (!called) {
      called = true;
      return fn(...args); // Return the result here
    }

    // Return undefined for subsequent calls
    return undefined;
  };
}