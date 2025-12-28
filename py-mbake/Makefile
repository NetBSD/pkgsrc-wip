# $NetBSD$

DISTNAME=	mbake-1.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mbake/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/EbodShojaei/bake/
COMMENT=	Makefile formatter and linter
LICENSE=	mit

USE_TOOLS+=	gmake:run

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-typer>=0.9.0:../../wip/py-typer
DEPENDS+=	${PYPKGPREFIX}-rich>=13.0.0:../../comms/py-rich

WRKSRC=		${WRKDIR}/${DISTNAME}

SUBST_CLASSES+=		make
SUBST_FILES.make+=	mbake/cli.py
SUBST_SED.make+=	-e 's,"make","'${GMAKE}'",'
SUBST_STAGE.make=	pre-build
SUBST_MESSAGE.make=	Fix to use GNU make.

# as of 1.4.4
# 2 failed, 171 passed

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.2.0:../../textproc/py-tomli
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} bake bake-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} mbake mbake-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
