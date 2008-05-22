# $NetBSD: Makefile,v 1.3 2008/05/22 15:38:47 tnn2 Exp $

DISTNAME=	py-kqueue-2.0
PKGNAME=	${PYPKGPREFIX}-twisted-kqueue-2.0
PKGREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jdolecek/

MAINTAINER=	milos.negovanovic@googlemail.com
COMMENT=	Python interface to kqueue, suitable for Twisted

PYDISTUTILSPKG= # defined

# need to get definition of PKG_HAVE_KQUEUE
.include "../../mk/bsd.prefs.mk"

.if !defined(PKG_HAVE_KQUEUE)
PKG_SKIP_REASON+= "${PKGNAME} is not available for ${MACHINE_PLATFORM}, needs OS support for kqueue(2)"
.endif

CONFLICTS+=	${PYPKGPREFIX}-kqueue-[0-9]*

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
