#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: strelay
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
   . /etc/rc.subr
fi

name="strelay"
rcvar="$name"
command="@PREFIX@/bin/syncthing-relaysrv"
command_args="2> @PKG_HOME@/var/log/syncthing-relaysrv.log &"
strelay_user=@STRELAY_USER@
strelay_group=@STRELAY_GROUP@
strelay_chroot="@PKG_HOME@"
chrootbuild_cmd="chrootbuild"
extra_commands="chrootbuild"

chrootbuild()
{
   if [ -s @PKG_HOME@/cert.pem -o -s @PKG_HOME@/key.pem ]; then
      @ECHO@ "Keyfiles still exist in @PKG_HOME@! (Re)move to continue!"
#      exit 1
   fi
   @ECHO@ "Purging @PKG_HOME@ ..."
   @RM@ -r @PKG_HOME@
   
   @ECHO@ "Populating @PKG_HOME@ ..."
   [ -f /etc/openssl/certs/ca-certificates.crt ] && \
      STROPTFILE="${STROPTFILE} /etc/openssl/certs/ca-certificates.crt"
   [ -f /etc/ssl/cert.pem ] && \
      STROPTFILE="${STROPTFILE} /etc/ssl/cert.pem"
   [ -f /system/etc/security/cacerts ] && \
      STROPTFILE="${STROPTFILE} /system/etc/security/cacerts"
   [ -f /usr/local/share/certs/ca-root-nss.crt ] && \
      STROPTFILE="${STROPTFILE} /usr/local/share/certs/ca-root-nss.crt"
   @INSTALL@ -d -o @STRELAY_USER@ -g @STRELAY_GROUP@ -m 0775 @PKG_HOME@
   @INSTALL@ -d -o @STRELAY_USER@ -g @STRELAY_GROUP@ -m 0775 @PKG_HOME@/var/log
   @PAX@ -rw -v /dev/urandom /etc/hosts /etc/nsswitch.conf /etc/resolv.conf \
      /lib/libc.so* /lib/libgcc_s.so* /libexec/ld.elf_so /usr/lib/libc.so* \
      /usr/lib/libgcc_s.so* /usr/lib/libpthread.so* /usr/libexec/ld.elf_so \
      ${STROPTFILE} @PREFIX@/bin/syncthing-relaysrv @PKG_HOME@
}

if [ ! -x @PKG_HOME@@PREFIX@/bin/syncthing-relaysrv ]; then
   eval chrootbuild
fi

load_rc_config $name
run_rc_command $1
