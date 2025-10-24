sudo ln -s /etc/nginx/sites-available/actix.com /etc/nginx/sites-enabled/
sudo nginx -t       # Test configuration
sudo systemctl reload nginx

git clone https://github.com/<web4application>/actix.git
cd actix

docker-compose up --build -d

docker-compose logs -f api
