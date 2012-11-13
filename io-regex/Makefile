# $NetBSD: Makefile,v 1.2 2012/11/13 22:25:33 othyro Exp $

.include "../../wip/io/version.mk"

PKGNAME=		io-regex-${IO_VERSION}
PKGREVISION=		0
CATEGORIES=		devel

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		www.iolanguage.com
COMMENT=		Regex addon for Io

ADDON_NAME=			Regex
ADDON_DEPENDS_ON_ADDONS=        Range

.include "../../devel/pcre/buildlink3.mk"
.include "../../wip/io/addon.mk"
.include "../../mk/bsd.pkg.mk"
