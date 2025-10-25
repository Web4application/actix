sudo ln -s /etc/nginx/sites-available/actix.com /etc/nginx/sites-enabled/
sudo nginx -t       # Test configuration
sudo systemctl reload nginx

git clone https://github.com/<web4application>/actix.git
cd actix

docker-compose up --build -d

docker-compose logs -f api

sudo apt install certbot python3-certbot-nginx
sudo certbot --nginx -d actix.com -d www.actix.com -d actix.io -d www.actix.io -d actix.ai -d www.actix.ai

sudo apt install certbot python3-certbot-nginx
sudo certbot --nginx -d actix.com -d www.actix.com -d actix.dev -d www.actix.dev -d reallms.dev -d www.reallms.dev 
docker compose build
docker compose up -d


netstat -ano | findstr :8081 taskkill /PID typeyourPIDhere /F

Read more here: https://locall.host/5557/
