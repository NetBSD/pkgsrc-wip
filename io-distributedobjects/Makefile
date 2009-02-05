# $NetBSD: Makefile,v 1.3 2009/02/05 23:08:14 milosn Exp $

.include "../../wip/io/version.mk"

PKGNAME=		io-distributedobjects-${IO_VERSION}
#PKGREVISION=		1
CATEGORIES=		devel

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		www.iolanguage.com
COMMENT=		DistributedObjects addon for Io.

DEPENDS+=       	io-socket>=${IO_VERSION}:../../wip/io-socket

ADDON_NAME=		DistributedObjects


.include "../../wip/io/addon.mk"
.include "../../mk/bsd.pkg.mk"
