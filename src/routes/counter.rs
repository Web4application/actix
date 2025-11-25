use actix_web::{get, post, web, HttpResponse};
use serde_json::json;
use sqlx::query;

use crate::state::AppState;

#[get("/api/counter")]
async fn get_counter(state: web::Data<AppState>) -> HttpResponse {
    let row: (i32,) = sqlx::query_as("SELECT value FROM counter WHERE id = 1")
        .fetch_one(&state.pool)
        .await
        .unwrap();

    HttpResponse::Ok().json(json!({ "value": row.0 }))
}

#[post("/api/counter/increment")]
async fn increment_counter(state: web::Data<AppState>) -> HttpResponse {
    let _ = query("UPDATE counter SET value = value + 1 WHERE id = 1")
        .execute(&state.pool)
        .await;

    let row: (i32,) = query!("SELECT value FROM counter WHERE id = 1")
        .fetch_one(&state.pool)
        .await
        .unwrap();

    HttpResponse::Ok().json(json!({ "value": row.value }))
}

pub fn counter_scope() -> actix_web::Scope {
    web::scope("").service(get_counter).service(increment_counter)
}
