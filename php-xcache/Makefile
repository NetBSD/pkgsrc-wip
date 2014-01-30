# $NetBSD: Makefile,v 1.8 2014/01/30 13:00:40 trontor Exp $

MODNAME=		xcache
PECL_VERSION=		3.1.0
PKGNAME=		${MODNAME}-${PECL_VERSION}
CATEGORIES=		www
MASTER_SITES=		http://xcache.lighttpd.net/pub/Releases/${PECL_VERSION}/
EXTRACT_SUFX=		.tar.bz2 # Override setting in "lang/php/ext.mk".

LICENSE=		modified-bsd

MAINTAINER=		vs@nifelheim.info
HOMEPAGE=		http://xcache.lighttpd.net/
COMMENT=		Fast and stable PHP opcode cacher

XCACHE_DIR=		${PREFIX}/share/xcache

USE_TOOLS+=		gm4 pax

PLIST_SRC+=		PLIST

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

INSTALLATION_DIRS=	share/examples/xcache
INSTALLATION_DIRS+=	share/xcache

do-install:
	${INSTALL_DATA} ${WRKSRC}/xcache.ini \
		${DESTDIR}${PREFIX}/share/examples/xcache/
	cd ${WRKSRC}/htdocs && ${PAX} -wr * ${DESTDIR}${XCACHE_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
