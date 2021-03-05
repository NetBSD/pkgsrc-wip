# $NetBSD$

DISTNAME=	alyahmor-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_PROJECT=	alyahmor
GITHUB_TAG=	654813ecd41ff0bcae14b82b40f18b1baa534962
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxscout/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/linuxscout/alyahmor/
COMMENT=	Alyahmor Arabic Morphological Genrator for Python
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-libqutrub>=1.0:../../wip/py-libqutrub
DEPENDS+=	${PYPKGPREFIX}-arabic>=0.6.2:../../wip/py-arabic

WRKSRC=		${WRKDIR}/alyahmor-654813ecd41ff0bcae14b82b40f18b1baa534962

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
