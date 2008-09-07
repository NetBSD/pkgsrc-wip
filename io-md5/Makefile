# $NetBSD: Makefile,v 1.1.1.1 2008/09/07 16:53:59 milosn Exp $

.include "../../wip/io/version.mk"

PKGNAME=		io-md5-${IO_VERSION}
PKGREVISION=		0
CATEGORIES=		devel

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		www.iolanguage.com
COMMENT=		MD5 addon for Io.

DEPENDS+=       	io-sha1>=${IO_VERSION}:../../wip/io-sha1

ADDON_NAME=		MD5

.include "../../wip/io/addon.mk"
.include "../../mk/bsd.pkg.mk"
