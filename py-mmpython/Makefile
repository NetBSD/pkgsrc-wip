# $NetBSD: Makefile,v 1.7 2005/11/20 19:25:03 dhowland Exp $
#

DISTNAME=		mmpython-0.4.9
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mmpython/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://mmpython.sourceforge.net/
COMMENT=		Extract text information from mp3, ogg, avi, jpg and more

DEPENDS+=               lsdvd>=0.10:../../multimedia/lsdvd

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
