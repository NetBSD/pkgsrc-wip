# $NetBSD$

DISTNAME=	visidata-3.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=v/visidata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://visidata.org/
COMMENT=	curses interface for exploring and arranging tabular data
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-openpyxl>=2.4:../../textproc/py-openpyxl
#DEPENDS+=	${PYPKGPREFIX}-standard-mailcap-[0-9]*:../../wip/py-standard-mailcap

SUBST_CLASSES+=		setuppy
SUBST_STAGE.setuppy=	pre-configure
SUBST_MESSAGE.setuppy=	Adjusting hard-coded man path
SUBST_FILES.setuppy=	setup.py
SUBST_SED.setuppy+=	-e 's,share/man,${PKGMANDIR},g'

USE_LANGUAGES=		# none

# Only for Python 3.x
PYTHON_VERSIONS_INCOMPATIBLE=	27

# We never had old tool and that would need special handling of custom shebang
post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/vd2to3.vdx

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
