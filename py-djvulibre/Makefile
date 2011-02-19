# $NetBSD: Makefile,v 1.5 2011/02/19 22:57:57 ryo-on Exp $
#
DISTNAME=	python-djvulibre-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	graphics textproc
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-djvulibre/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://jwilk.net/software/python-djvulibre
COMMENT=	Python bindings for the DjVuLibre library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-pyrex-[0-9]*:../../lang/py-pyrex
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_TOOLS+=	pkg-config #gsed
#DEPENDS+=	gsed-[0-9]*:../../textproc/gsed

USE_LANGUAGES=	c

PYTHON_VERSIONS_ACCEPTED=	26 25
PYDISTUTILSPKG=	yes

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
