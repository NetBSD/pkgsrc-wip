# $NetBSD: Makefile,v 1.2 2008/09/10 20:10:37 milosn Exp $

.include "../../wip/io/version.mk"

PKGNAME=		io-distributedobjects-${IO_VERSION}
PKGREVISION=		1
CATEGORIES=		devel

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		www.iolanguage.com
COMMENT=		DistributedObjects addon for Io.

DEPENDS+=       	io-socket>=${IO_VERSION}:../../wip/io-socket

ADDON_NAME=		DistributedObjects


.include "../../wip/io/addon.mk"
.include "../../mk/bsd.pkg.mk"
