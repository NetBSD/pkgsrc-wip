# $NetBSD: Makefile,v 1.6 2014/05/09 07:38:47 thomasklausner Exp $

DISTNAME=	gpaw-0.9.0.8965
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	https://wiki.fysik.dtu.dk/gpaw-files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://wiki.fysik.dtu.dk/gpaw/
COMMENT=	Grid-based real-space PAW method DFT code
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-ase-[0-9]*:../../wip/py-ase

USE_LANGUAGES=	c c99
EGG_NAME=	gpaw-0.9.0
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2 and py-gobject via py-ase

post-extract:
	${MV} ${WRKSRC}/tools/gpaw ${WRKSRC}/tools/gpaw${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/gpaw-basis ${WRKSRC}/tools/gpaw-basis${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/gpaw-mpisim ${WRKSRC}/tools/gpaw-mpisim${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/gpaw-setup ${WRKSRC}/tools/gpaw-setup${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/gpaw-test ${WRKSRC}/tools/gpaw-test${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
