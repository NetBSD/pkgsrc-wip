# $NetBSD: Makefile,v 1.4 2013/12/07 16:17:30 jihbed Exp $

DISTNAME=	gpaw-0.9.0.8965
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	https://wiki.fysik.dtu.dk/gpaw-files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://wiki.fysik.dtu.dk/gpaw/
COMMENT=	Grid-based real-space PAW method DFT code
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c99
PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-extract:
	${MV} ${WRKSRC}/tools/gpaw ${WRKSRC}/tools/gpaw${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/gpaw-basis ${WRKSRC}/tools/gpaw-basis${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/gpaw-mpisim ${WRKSRC}/tools/gpaw-mpisim${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/gpaw-setup ${WRKSRC}/tools/gpaw-setup${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/gpaw-test ${WRKSRC}/tools/gpaw-test${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-ase-[0-9]*:../../wip/py-ase
.include "../../mk/bsd.pkg.mk"
