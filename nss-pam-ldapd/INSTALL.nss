# $NetBSD: INSTALL.nss $

case ${STAGE} in
	POST-INSTALL)
		${LN} -sf ${PREFIX}/lib/nss_ldap.so.0 /usr/lib
		${LN} -sf ${PREFIX}/lib/security/pam_ldap.so /usr/lib/security
		;;
esac
