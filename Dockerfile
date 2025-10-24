FROM rust:1.79 as builder
WORKDIR /usr/src/app
COPY Cargo.toml Cargo.lock ./
RUN mkdir src && echo "fn main() {}" > src/main.rs
RUN cargo build --release || true
COPY ./src ./src
RUN cargo build --release

FROM debian:bullseye-slim
WORKDIR /usr/src/app
COPY --from=builder /usr/src/app/target/release/actix_ .
COPY .env ./
EXPOSE 8080
CMD ["./actix"]
