# $NetBSD: Makefile,v 1.1.1.1 2011/03/07 10:12:56 jihbed Exp $
#

DISTNAME=	gpaw-0.7.2.6974
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	https://wiki.fysik.dtu.dk/gpaw-files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://wiki.fysik.dtu.dk/gpaw/
COMMENT=	Grid-based real-space PAW method DFT code
LICENSE=	gnu-gpl-v3

#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

FETCH_USING=		wget
FETCH_BEFORE_ARGS=	--no-check-certificate

USE_LANGUAGES=	c c99
PYDISTUTILSPKG=	yes

post-extract:
	${MV} ${WRKSRC}/tools/gpaw ${WRKSRC}/tools/gpaw${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/gpaw-basis ${WRKSRC}/tools/gpaw-basis${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/gpaw-mpisim ${WRKSRC}/tools/gpaw-mpisim${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/gpaw-setup ${WRKSRC}/tools/gpaw-setup${PYVERSSUFFIX}
	${MV} ${WRKSRC}/tools/gpaw-test ${WRKSRC}/tools/gpaw-test${PYVERSSUFFIX}

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
