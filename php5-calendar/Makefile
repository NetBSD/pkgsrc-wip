# $NetBSD: Makefile,v 1.1.1.1 2004/07/16 19:08:55 ppostma Exp $

MODNAME=		calendar
CATEGORIES+=		misc
PKGREVISION=		# empty
COMMENT=		PHP5 extension for calendar conversion support

USE_BUILDLINK3= 	YES

.include "../../wip/php5/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
