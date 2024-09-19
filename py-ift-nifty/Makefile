# $NetBSD: Makefile,v 1.1 2015/08/05 21:06:54 jihbed Exp $

DISTNAME=	ift-nifty-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ift_nifty/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.mpa-garching.mpg.de/ift/nifty/
COMMENT=	Numerical Information Field Theory
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/nifty-1.0.7

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
