# $NetBSD: Makefile,v 1.7 2013/08/07 08:13:31 makoto Exp $

.include "../../wip/ja-freewnn-lib/Makefile.common"

PKGNAME=	ja-FreeWnn-lib-1.11alpha22
# DISTFILE now includes all patches, the same PKGNAME, almost the same binary
# but build is different, and binary may not be exactly the same
PKGREVISION=	1

COMMENT+=	(Japanese client library)

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-client
CONFIGURE_ARGS+=	--disable-cWnn
CONFIGURE_ARGS+=	--disable-kWnn

INSTALL_TARGET=		install install.man

.include "../../mk/bsd.pkg.mk"
