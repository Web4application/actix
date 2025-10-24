
git clone https://github.com/<web4application>/actix.git
cd actix

docker-compose up --build -d

docker-compose logs -f api
