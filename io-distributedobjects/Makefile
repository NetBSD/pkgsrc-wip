# $NetBSD: Makefile,v 1.1.1.1 2008/09/06 23:55:00 milosn Exp $

.include "../../wip/io/version.mk"

PKGNAME=		io-distributedobjects-${IO_VERSION}
PKGREVISION=		0
CATEGORIES=		devel

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		www.iolanguage.com
COMMENT=		DistributedObjects addon for Io.

DEPENDS+=       	io-socket>=${IO_VERSION}:../../wip/io-socket

ADDON_NAME=		DistributedObjects


.include "../../wip/io/addon.mk"
.include "../../mk/bsd.pkg.mk"
