# $NetBSD: Makefile,v 1.5 2012/11/13 22:25:33 othyro Exp $

.include "../../wip/io-base/version.mk"

PKGNAME=		${DISTNAME:S/io-/&socket-/}
CATEGORIES=		net
LICENSE=		modified-bsd

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		http://www.iolanguage.com/
COMMENT=		Socket addon for Io

ADDON_NAME=		Socket

.include "../../wip/io-base/addon.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
