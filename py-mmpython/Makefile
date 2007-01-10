# $NetBSD: Makefile,v 1.11 2007/01/10 23:34:49 absd Exp $
#

DISTNAME=		mmpython-0.4.10
PKGREVISION=		1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mmpython/}

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://mmpython.sourceforge.net/
COMMENT=		Extract text information from mp3, ogg, avi, jpg and more

DEPENDS+=		lsdvd>=0.10:../../multimedia/lsdvd

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
