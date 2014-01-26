# $NetBSD: Makefile,v 1.7 2014/01/26 18:41:45 mjoellnir Exp $
#

MODNAME=		xcache
PECL_VERSION=		3.1.0
PKGNAME=		${MODNAME}-${PECL_VERSION}
CATEGORIES=		www
MASTER_SITES=		http://xcache.lighttpd.net/pub/Releases/${PECL_VERSION}/
EXTRACT_SUFX=		.tar.bz2 # required, because ../../lang/php/ext.mk
				 # overrides it with .tgz

LICENSE=		modified-bsd

# Original Maintainer (until dec 2010)
#MAINTAINER=		mbowie@buzmo.com
# Maintainer from dec 2010 on
MAINTAINER=		vs@nifelheim.info
HOMEPAGE=		http://xcache.lighttpd.net/
COMMENT=		Fast and stable PHP opcode cacher

XCACHE_DIR=		${PREFIX}/share/xcache

USE_TOOLS+=		pax

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
