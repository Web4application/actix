# Use Rust official image
FROM rust:1.79 as builder

WORKDIR /usr/src/app

# Copy Cargo.toml and lock first to leverage caching
COPY Cargo.toml Cargo.lock ./
RUN mkdir src && echo "fn main() {}" > src/main.rs
RUN cargo build --release || true

# Copy source code
COPY ./src ./src
RUN rm -rf target/release/deps/my_actix_api*
RUN cargo build --release

# Runtime stage
FROM debian:bullseye-slim
WORKDIR /usr/src/app
COPY --from=builder /usr/src/app/target/release/my_actix_api .
COPY .env ./

EXPOSE 8080

CMD ["./my_actix_api"]
