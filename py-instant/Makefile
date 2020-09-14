# $NetBSD$

DISTNAME=	instant-2017.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/19/af/4cce8fbd13b348950bf0d7cde2c9c46a065301b61c47aae294dd7fafc98f/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://bitbucket.org/fenics-project/instant/
COMMENT=	Instant Inlining of C/C++ in Python
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/scripts/instant-clean ${WRKSRC}/scripts/instant-clean${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/instant-showcache ${WRKSRC}/scripts/instant-showcache${PYVERSSUFFIX}
	
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
