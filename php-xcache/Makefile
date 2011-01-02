# $NetBSD: Makefile,v 1.4 2011/01/02 09:47:21 mjoellnir Exp $
#

MODNAME=		xcache
PECL_VERSION=		1.3.1
PKGNAME=		${MODNAME}-${PECL_VERSION}
CATEGORIES=		www
MASTER_SITES=		http://xcache.lighttpd.net/pub/Releases/${PECL_VERSION}/
EXTRACT_SUFX=		.tar.gz # required, because ../../lang/php/ext.mk 
				# overrides it with .tgz

# Original Maintainer (since dec 2010)
#MAINTAINER=		mbowie@buzmo.com
# Maintainer from dec 2010 on
MAINTAINER=		vs@nifelheim.info
HOMEPAGE=		http://xcache.lighttpd.net/
COMMENT=		Fast and stable PHP opcode cacher

PLIST_SRC+=		PLIST

PKG_DESTDIR_SUPPORT=	user-destdir


CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

INSTALLATION_DIRS=	share/examples/xcache
INSTALLATION_DIRS+=	share/xcache
INSTALLATION_DIRS+=	share/xcache/admin
INSTALLATION_DIRS+=	share/xcache/coverager

ADMINFILES=		common-en.lang.php common-zh-simplified-utf-8.lang.php \
			common-zh-traditional-utf-8.lang.php common.php \
			config.php.example edit.php edit.tpl.php footer.tpl.php \
			header.tpl.php help-en.lang.php \
			help-zh-simplified-utf-8.lang.php \
			help-zh-traditional-utf-8.lang.php help.php index.php \
			tablesort.js xcache.css xcache.php xcache.tpl.php

COVERAGERFILES=		common-en.lang.php common-zh-simplified-utf-8.lang.php \
			common-zh-simplified-gb2312.lang.php common.php \
			config.php.example coverager.css coverager.php \
			coverager.tpl.php index.php


do-install:
	${INSTALL_DATA} ${WRKSRC}/xcache.ini \
		${DESTDIR}${PREFIX}/share/examples/xcache/
.for f in ${ADMINFILES}
	${INSTALL_DATA} ${WRKSRC}/admin/${f} \
		${DESTDIR}${PREFIX}/share/xcache/admin/
.endfor
.for f in ${COVERAGERFILES}
	${INSTALL_DATA} ${WRKSRC}/coverager/${f} \
		${DESTDIR}${PREFIX}/share/xcache/coverager/
.endfor


.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
