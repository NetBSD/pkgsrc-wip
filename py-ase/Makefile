# $NetBSD: Makefile,v 1.11 2014/06/01 12:49:38 thomasklausner Exp $

DISTNAME=	python-ase-3.8.1.3440
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	2
CATEGORIES=	biology python
MASTER_SITES=	https://wiki.fysik.dtu.dk/ase-files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://wiki.fysik.dtu.dk/ase/
COMMENT=	Atomic Simulation Environment
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2, py-gobject

post-extract:
	${MV} ${WRKSRC}/tools/ase-build ${WRKSRC}/tools/ase-build${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/ase-info ${WRKSRC}/tools/ase-info${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/ase-db ${WRKSRC}/tools/ase-db${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/ase-run ${WRKSRC}/tools/ase-run${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/ase-gui ${WRKSRC}/tools/ase-gui${PYVERSSUFFIX}

## It is highly recommended (but not required) to install also these:
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

##required for basic ASE functionality
.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
