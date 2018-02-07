# $NetBSD: Makefile,v 1.1 2014/10/03 21:12:34 jihbed Exp $

DISTNAME=	speview-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/speview/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ximeg/speview
COMMENT=	Program to display binary SPE files containing Raman spectra
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-xcal-raman>=0.1.5:../../wip/py-xcal-raman
DEPENDS+=	${PYPKGPREFIX}-zenity>=0.1.4:../../wip/py-zenity

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-xcal-raman

post-extract:
	${MV} ${WRKSRC}/speview.py ${WRKSRC}/speview.py${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
