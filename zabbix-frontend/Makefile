# $NetBSD: Makefile,v 1.1 2015/01/21 22:56:43 heidnes Exp $

PKGNAME=	zabbix-frontend-${VER}

.include "../../wip/zabbix/Makefile.common"

CONFIGURE_ARGS+=--disable-agent
CONFIGURE_ARGS+=--disable-server
CONFIGURE_ARGS+=--disable-proxy

do-install:
	cd ${WRKSRC}; pax -rw frontends \
		${DESTDIR}${PREFIX}/share/zabbix/

.include "../../mk/bsd.pkg.mk"
