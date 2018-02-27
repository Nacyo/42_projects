diff="/tmp/diff"
file="/etc/crontab"
result="md5sum -c crontab.checksum /etc/crontab"
$result > diff
if grep "FAILED" $diff
then
	echo "FILE MODIFIED $file" | mail -s "file modified : $file" root
fi

# do md5sum /etc/crontab/ > crontab.checksum before running script
# add crontab 0 0 * * * sudo sh 04.sh
