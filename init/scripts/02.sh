sudo apt-get update -y > /var/log/update_script.log && sudo apt-get upgrade -y >> /var/log/update_script.log

#ajouter a crontab 0 4 * * 1 sudo sh 02.sh
