# $NetBSD: Makefile,v 1.13 2014/12/31 13:58:32 thomasklausner Exp $

DISTNAME=	python-djvulibre-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	graphics textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-djvulibre/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://jwilk.net/software/python-djvulibre
COMMENT=	Python bindings for the DjVuLibre library
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-pyrex-[0-9]*:../../lang/py-pyrex

USE_TOOLS+=	pkg-config #gsed
#DEPENDS+=	gsed-[0-9]*:../../textproc/gsed

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-pyrex

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-configure
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e "s,\['cython,\['cython${PYVERSSUFFIX},"
SUBST_SED.setup+=	-e "s/'sed', '-i~',/'sed', '-n',/"

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/pyversion.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
