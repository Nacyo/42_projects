while IFS=: read -r login pwd uid gid id_info homedir cmd
do 
 echo "login: $login UID: $uid path: $homedir"
done < /etc/passwd
