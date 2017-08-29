# $NetBSD$

DISTNAME=	pydenticon-0.3
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     devel python
MASTER_SITES=   ${MASTER_SITE_PYPI:=p/pydenticon/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/azaghal/pydenticon
COMMENT=	Library for generating identicons
LICENSE=	modified-bsd


DEPENDS+= ${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
WRKSRC=		${WRKDIR}/pydenticon-0.3
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
