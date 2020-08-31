# $NetBSD$

DISTNAME=	cysignals-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/6c/29/ddd51b4f514ce7c554758eab63995024136f257f3d33ae14527d7d75705d/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/sagemath/cysignals
COMMENT=	Interrupt and signal handling for Cython
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8.3:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-sphinx

GNU_CONFIGURE=	NO

post-extract:
	${MV} ${WRKSRC}/src/scripts/cysignals-CSI ${WRKSRC}/src/scripts/cysignals-CSI${PYVERSSUFFIX}

BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
