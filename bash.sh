npm run gendocs
docs/build.rst
mkdir -p docs
rustdoc2rst target/doc/dev_ml.json > docs/dev.rst
cargo doc --no-deps --document-private-items --output-format json
cargo install rustdoc2rst
