#!@SH@
exec @PREFIX@/lib/sickbeard/SickBeard.py \
	--datadir=@PKG_SYSCONFDIR@/sickbeard \
	--pidfile=/var/run/sickbeard.pid \
	"$@"
