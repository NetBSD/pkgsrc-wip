# $NetBSD: Makefile,v 1.1 2015/01/18 21:33:00 jihbed Exp $

DISTNAME=	etmtk-3.0.43
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PYPI:=e/etmtk/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://people.duke.edu/~dgraham/etmtk
COMMENT=	Event and task manager
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-icalendar>=3.8.3:../../time/py-icalendar
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_LANGUAGES=	# none

#PYTHON_VERSIONS_ACCEPTED=	27

post-extract:
	${MV} ${WRKSRC}/etm ${WRKSRC}/etm${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
