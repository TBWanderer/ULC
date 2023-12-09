{
	inputs = {
		nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
	};

	outputs = {self, nixpkgs}:
	let system = "x86_64-linux";
	pkgs = import nixpkgs { inherit system; };
	in {
		packages."${system}".default = pkgs.stdenv.mkDerivation {
			# Main info
			name = "cpp-template";
			src = ./.;

			# Dependencies
			nativeBuildInputs = with pkgs; [
				just
				gcc
			];
			buildInputs = with pkgs; [
				# Some libraries
			];
			
			# Phases
			buildPhase = "just build"; # Build project using just (justfile)
			installPhase = "cp out $out"; # Copy output to 'result' (symlink appears in this directory, if you run "nix build")
		};
		gen_compile_commands = pkgs.mkShell { # We need this to generate compile_commands.json
			packages = [
				self.packages."${system}".default.nativeBuildInputs
				self.packages."${system}".default.buildInputs
				pkgs.bear
			];
			shellHook = "bear -- just build && rm out && exit";
		};
		devShells."${system}".default = pkgs.mkShell {
			packages = [
				self.packages."${system}".default.nativeBuildInputs
				self.packages."${system}".default.buildInputs
			];
			shellHook = "eval $SHELL && exit";
		};
	};
}
