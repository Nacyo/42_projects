ifconfig | grep "ether" | tr "\t" " " | sed -e 's/ //g' | sed 's/ether//g'
