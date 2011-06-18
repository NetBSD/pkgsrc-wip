# $NetBSD: Makefile,v 1.6 2011/06/18 11:29:24 obache Exp $

.include "../../wip/ja-freewnn-lib/Makefile.common"

PKGNAME=	ja-FreeWnn-lib-1.11alpha22

COMMENT+=	(Japanese client library)

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-client
CONFIGURE_ARGS+=	--disable-cWnn
CONFIGURE_ARGS+=	--disable-kWnn

INSTALL_TARGET=		install install.man

.include "../../mk/bsd.pkg.mk"
