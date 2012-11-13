# $NetBSD: Makefile,v 1.2 2012/11/13 22:25:33 othyro Exp $

.include "../../wip/io/version.mk"

PKGNAME=		io-md5-${IO_VERSION}
PKGREVISION=		0
CATEGORIES=		devel

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		www.iolanguage.com
COMMENT=		MD5 addon for Io

DEPENDS+=       	io-sha1>=${IO_VERSION}:../../wip/io-sha1

ADDON_NAME=		MD5

.include "../../wip/io/addon.mk"
.include "../../mk/bsd.pkg.mk"
