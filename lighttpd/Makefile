# $NetBSD: Makefile,v 1.3 2005/02/22 14:02:07 socrtp Exp $

DISTNAME=		lighttpd-1.3.11
# PKGNAME=		lighttpd-1.3.10
CATEGORIES=		www
MASTER_SITES=		http://lighttpd.net/download/

MAINTAINER=		socrtp@soclab.eu.org
HOMEPAGE=		http://lighttpd.net/
COMMENT=		Fast as lightning HTTP server

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_PKGINSTALL=		YES

WRKSRC=			${WRKDIR}/${PKGNAME}
DOCDIR=			${PREFIX}/share/doc/lighttpd
EGDIR=			${PREFIX}/share/examples/lighttpd
RCD_SCRIPTS=		lighttpd
PKG_SYSCONFSUBDIR?=	lighttpd

LIGHTTPD_USER?=		www
LIGHTTPD_GROUP?=	www

PKG_GROUPS=		${LIGHTTPD_GROUP}
PKG_USERS=		${LIGHTTPD_USER}:${LIGHTTPD_GROUP}

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/lighttpd

PKG_OPTIONS_VAR	=	PKG_OPTIONS.lighttpd
PKG_SUPPORTED_OPTIONS=	inet6 mysql ssl
.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql_client}
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.endif

CONF_FILES=		${EGDIR}/lighttpd.conf ${PKG_SYSCONFDIR}/lighttpd.conf

post-patch:
	${SED} -e s,@@LIGHTTPD_USER@@,${LIGHTTPD_USER}, 			\
	    -e s,@@LIGHTTPD_GROUP@@,${LIGHTTPD_GROUP},				\
	    ${WRKSRC}/doc/lighttpd.conf > ${WRKSRC}/doc/lighttpd.conf.new
	${MV} ${WRKSRC}/doc/lighttpd.conf.new ${WRKSRC}/doc/lighttpd.conf

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/tests
	for i in ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/*.ps.gz ${WRKSRC}/doc/*.dot; do	\
		${INSTALL_DATA} $${i} ${DOCDIR};					\
	done
	for i in AUTHORS COPYING ChangeLog NEWS README; do	\
		${INSTALL_DATA} ${WRKSRC}/$${i} ${DOCDIR};	\
	done
	for i in lighttpd.conf lighttpd.user rrdtool-graph.sh spawn-php.sh; do	\
		${INSTALL_DATA} ${WRKSRC}/doc/$${i} ${EGDIR};			\
	done
	for i in lighttpd.conf fastcgi-10.conf fastcgi-11.conf fastcgi-12.conf; do	\
		${INSTALL_DATA} ${WRKSRC}/tests/$${i} ${EGDIR}/tests;			\
	done

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
