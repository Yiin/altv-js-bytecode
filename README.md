# alt:V JS Bytecode Compiler

# Important information
## Updating flags hash

There is an internal check V8 does in the bytecode to check if the compiled V8 flags and the used V8 flags are the same,
because the bytecode module needs to use an additional flag that Client JS doesn't use (`--flush-bytecode`), we need to overwrite
the flags hash in the bytecode with the hash used in Client JS.

To update the flags hash because the V8 flags used in Client JS have changed, update the V8 flags used by the module temporarily to
exactly those used by Client JS, then use the debug log in `CompileFilesToBytecode` to display the current flags hash.
Start the server once and take the flags hash from the debug log and overwrite the old flags hash variable with the new hash value.
Now make sure to change the flags again so they are *exactly* those in Client JS (+ `--flush-bytecode`).

## Updating the V8 version

The bytecode module needs to always use the same version as the version used in Client JS, fortunately we store the V8 binary
we use on the alt:V CDN, so this module downloads it from there. The V8 version should always be in sync of that, but we need
to make sure we make a new release of the bytecode module when we update the V8 version, so that the module is working again.
 