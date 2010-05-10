# $NetBSD: Makefile,v 1.2 2010/05/10 10:04:47 obache Exp $
#

MODNAME=		xcache
PECL_VERSION=		1.2.2
CATEGORIES=		www
MASTER_SITES=		http://xcache.lighttpd.net/pub/Releases/${PECL_VERSION}/
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		mbowie@buzmo.com
HOMEPAGE=		http://xcache.lighttpd.net/
COMMENT=		Fast and stable PHP opcode cacher

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-${MODNAME}

INSTALLATION_DIRS=	share/examples/xcache
INSTALLATION_DIRS+=	share/examples/xcache/admin

ADMINFILES=		common-en.lang.php common-zh-simplified-utf-8.lang.php \
			common-zh-traditional-utf-8.lang.php common.php \
			config.php.example edit.php edit.tpl.php footer.tpl.php \
			header.tpl.php help-en.lang.php \
			help-zh-simplified-utf-8.lang.php \
			help-zh-traditional-utf-8.lang.php help.php index.php \
			tablesort.js xcache.css xcache.php xcache.tpl.php

post-install:
	${INSTALL_DATA} ${WRKSRC}/xcache.ini \
		${DESTDIR}${PREFIX}/share/examples/xcache/
.for f in ${ADMINFILES}
	${INSTALL_DATA} ${WRKSRC}/admin/${f} \
		${DESTDIR}${PREFIX}/share/examples/xcache/admin/
.endfor

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
