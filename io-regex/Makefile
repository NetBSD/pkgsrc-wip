# $NetBSD: Makefile,v 1.3 2012/11/13 23:05:28 othyro Exp $

.include "../../wip/io-base/version.mk"

PKGNAME=		io-regex-${IO_VERSION}
CATEGORIES=		devel

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		www.iolanguage.com
COMMENT=		Regex addon for Io

ADDON_NAME=			Regex
ADDON_DEPENDS_ON_ADDONS=	Range

.include "../../devel/pcre/buildlink3.mk"
.include "../../wip/io-base/addon.mk"
.include "../../mk/bsd.pkg.mk"
