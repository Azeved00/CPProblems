{ pkgs ? import <nixpkgs> {  }}:
let
    root = builtins.getEnv "PWD";

in 
pkgs.mkShell {
    ROOT=root;

    name = "AOC-rust";

    buildInputs = with pkgs; [
        rustc
        cargo
    ];

    shellHook = ''
        echo -ne "\033]0;Rust Development\007"

        alias build='cargo build'
        
        alias exec='cargo run'
    '';
}
