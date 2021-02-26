# $NetBSD$

DISTNAME=	ppft-1.6.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/ppft/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/ppft
COMMENT=	Distributed and parallel python
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	${PYPKGPREFIX}-six>=1.7.3:../../lang/py-six


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
