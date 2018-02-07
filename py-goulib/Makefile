# $NetBSD$

DISTNAME=	Goulib-1.9.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/Goulib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/goulu/goulib
COMMENT=	Library of useful Python code for scientific + technical applications
LICENSE=	gnu-lgpl-v3

#DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.4.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.6.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-xlrd>=0.9.3:../../textproc/py-xlrd
BUILD_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 1.9.11

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
