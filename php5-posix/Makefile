# $NetBSD: Makefile,v 1.1.1.1 2004/07/16 19:11:34 ppostma Exp $

MODNAME=		posix
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP5 extension for POSIX-like functions

USE_BUILDLINK3=		YES

.include "../../wip/php5/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
