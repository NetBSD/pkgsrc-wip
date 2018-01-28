# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:26 asau Exp $
#

DISTNAME=	389-ds-base-1.2.2
CATEGORIES=	databases
MASTER_SITES=	http://directory.fedoraproject.org/sources/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://www.port389.org/
COMMENT=	389 Directory Server (LDAP) Base package
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl autoconf automake aclocal

DEPENDS+=	p5-mozldap-[0-9]*:../../wip/p5-mozldap

CONFIGURE_ARGS+=	--with-netsnmp=${PREFIX}
CONFIGURE_ARGS+=	--with-db=${PREFIX}
CONFIGURE_ARGS+=	--with-sasl=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/nspr
CFLAGS+=		-I${BUILDLINK_DIR}/include/nspr
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/nss/nss
CFLAGS+=		-I${BUILDLINK_DIR}/include/nss/nss
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/ldap
CFLAGS+=		-I${BUILDLINK_DIR}/include/ldap

EGDIR=			${PREFIX}/share/examples/389-ds-base
CONF_FILES+=		${EGDIR}/dirsrv/config/certmap.conf ${PKG_SYSCONFDIR}/dirsrv/config/certmap.conf
CONF_FILES+=		${EGDIR}/dirsrv/config/slapd-collations.conf ${PKG_SYSCONFDIR}/dirsrv/config/slapd-collations.conf
CONF_FILES+=		${EGDIR}/dirsrv/schema/00core.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/00core.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/01common.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/01common.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/05rfc2247.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/05rfc2247.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/05rfc2927.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/05rfc2927.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/10rfc2307.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/10rfc2307.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/20subscriber.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/20subscriber.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/25java-object.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/25java-object.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/28pilot.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/28pilot.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/30ns-common.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/30ns-common.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/50ns-admin.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/50ns-admin.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/50ns-certificate.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/50ns-certificate.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/50ns-directory.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/50ns-directory.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/50ns-mail.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/50ns-mail.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/50ns-value.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/50ns-value.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/50ns-web.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/50ns-web.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/60autofs.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/60autofs.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/60eduperson.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/60eduperson.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/60mozilla.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/60mozilla.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/60nss-ldap.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/60nss-ldap.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/60pam-plugin.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/60pam-plugin.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/60pureftpd.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/60pureftpd.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/60rfc2739.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/60rfc2739.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/60rfc3712.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/60rfc3712.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/60sabayon.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/60sabayon.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/60sudo.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/60sudo.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/60trust.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/60trust.ldif
CONF_FILES+=		${EGDIR}/dirsrv/schema/99user.ldif ${PKG_SYSCONFDIR}/dirsrv/schema/99user.ldif
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC} && automake

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_SYSCONFDIR}/dirsrv
	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_SYSCONFDIR}/dirsrv/schema
	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_SYSCONFDIR}/dirsrv/config

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../wip/svrcore/buildlink3.mk"
.include "../../wip/mozldap/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
