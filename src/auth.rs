use actix_web::{post, web, HttpResponse};
use serde::{Deserialize, Serialize};
use jsonwebtoken::{encode, EncodingKey, Header};

#[derive(Serialize, Deserialize)]
struct Claims {
    sub: String,
    exp: usize,
}

#[derive(Deserialize)]
struct LoginBody {
    username: String,
    password: String,
}

#[post("/api/auth/login")]
async fn login(body: web::Json<LoginBody>) -> HttpResponse {
    if body.username != "admin" || body.password != "password" {
        return HttpResponse::Unauthorized().finish();
    }

    let claims = Claims {
        sub: body.username.clone(),
        exp: 2000000000,
    };

    let token = encode(
        &Header::default(),
        &claims,
        &EncodingKey::from_secret("SECRET".as_ref()),
    )
    .unwrap();

    HttpResponse::Ok().json(serde_json::json!({ "token": token }))
}

pub fn auth_scope() -> actix_web::Scope {
    web::scope("").service(login)
}
