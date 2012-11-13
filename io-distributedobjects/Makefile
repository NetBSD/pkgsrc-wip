# $NetBSD: Makefile,v 1.4 2012/11/13 22:25:32 othyro Exp $

.include "../../wip/io/version.mk"

PKGNAME=		io-distributedobjects-${IO_VERSION}
#PKGREVISION=		1
CATEGORIES=		devel

MAINTAINER=		milos.negovanovic@googlemail.com
HOMEPAGE=		www.iolanguage.com
COMMENT=		DistributedObjects addon for Io

DEPENDS+=       	io-socket>=${IO_VERSION}:../../wip/io-socket

ADDON_NAME=		DistributedObjects


.include "../../wip/io/addon.mk"
.include "../../mk/bsd.pkg.mk"
