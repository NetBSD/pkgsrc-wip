# $NetBSD: Makefile,v 1.2 2012/11/13 23:05:28 othyro Exp $

.include "../../wip/io-base/version.mk"

PKGNAME=		io-sqlite3-${IO_VERSION}
CATEGORIES=		databases
LICENSE=		modified-bsd

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		http://www.iolanguage.com/
COMMENT=		SQLite3 addon for Io

ADDON_NAME=		SQLite3

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../wip/io-base/addon.mk"
.include "../../mk/bsd.pkg.mk"
