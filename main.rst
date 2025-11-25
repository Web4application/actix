use actix_web::{get, post, web, App, HttpResponse, HttpServer};
use std::sync::{Arc, Mutex};

#[derive(Clone)]
struct AppState {
    counter: Arc<Mutex<i32>>,
}

#[get("/api/counter")]
async fn get_counter(state: web::Data<AppState>) -> HttpResponse {
    let count = *state.counter.lock().unwrap();
    HttpResponse::Ok().json(serde_json::json!({ "value": count }))
}

#[post("/api/counter/increment")]
async fn increment_counter(state: web::Data<AppState>) -> HttpResponse {
    let mut num = state.counter.lock().unwrap();
    *num += 1;
    HttpResponse::Ok().json(serde_json::json!({ "value": *num }))
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    let shared_state = AppState {
        counter: Arc::new(Mutex::new(0)),
    };

    println!("🚀 Server running at http://127.0.0.1:8080");

    HttpServer::new(move || {
        App::new()
            .app_data(web::Data::new(shared_state.clone()))
            .service(get_counter)
            .service(increment_counter)
            .service(
                actix_files::Files::new("/", "./static")
                    .index_file("index.html")
            )
    })
    .bind(("0.0.0.0", 8080))?
    .run()
    .await
}
