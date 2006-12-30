# $NetBSD: Makefile,v 1.10 2006/12/30 10:03:30 absd Exp $
#

DISTNAME=		mmpython-0.4.10
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
