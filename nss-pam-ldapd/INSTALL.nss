# $NetBSD: INSTALL.nss $

case ${STAGE} in
	POST-INSTALL)
		${LN} -sf ${PREFIX}/lib/nss_ldap.so.0 /usr/lib ;;
esac
