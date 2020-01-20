# $NetBSD$

DISTNAME=	visidata-1.5.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=v/visidata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://visidata.org/
COMMENT=	curses interface for exploring and arranging tabular data
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-openpyxl-[0-9]*:../../textproc/py-openpyxl

SUBST_CLASSES+=		setuppy
SUBST_STAGE.setuppy=	pre-configure
SUBST_MESSAGE.setuppy=	Adjusting hard-coded man path
SUBST_FILES.setuppy=	setup.py
SUBST_SED.setuppy+=	-e 's,share/man,${PKGMANDIR},g'

USE_LANGUAGES=		# none

# Only for Python 3.x
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
