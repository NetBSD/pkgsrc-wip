#!@RCD_SCRIPTS_SHELL@
/bin/mkdir -p $2/share/doc/shoutcast
/usr/bin/install -m 0555 -o 0 -g 0 $1/README $2/share/doc/shoutcast/README.shoutcast
/usr/bin/install -m 0555 -o 0 -g 0 $1/sc_serv $2/bin
/bin/mkdir -p $3
/usr/bin/install -m 0555 -o 0 -g 0 $1/sc_serv.conf $3
/bin/mkdir -p $2/share/shoutcast/content
/usr/bin/install -m 0555 -o 0 -g 0 $1/content/scpromo.mp3 $2/share/shoutcast/content/scpromo.mp3
/bin/mkdir -p /var/log/shoutcast
