# $NetBSD: DEINSTALL.nss $

case ${STAGE} in
	POST-DEINSTALL)
		${RM} -f /usr/lib/nss_ldap.so.0 ;;
esac
