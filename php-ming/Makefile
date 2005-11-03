# $NetBSD: Makefile,v 1.1.1.1 2005/11/03 16:42:56 obache Exp $

MODNAME=		ming
CATEGORIES+=		graphics

MAINTAINER=		obata@lins.jp
COMMENT=		PHP extension for Ming library

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.ming}

.include "../../wip/ming/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
