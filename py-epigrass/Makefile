# $NetBSD: Makefile,v 1.3 2014/01/26 15:49:54 thomasklausner Exp $

DISTNAME=	epigrass-2.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	https://pypi.python.org/packages/source/e/epigrass/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/epigrass/
COMMENT=	Epidemiological Geo-Referenced Analysis and Simulation System
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/epigrass-2.3.1
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-mysqldb>=1.2.3:../../databases/py-mysqldb
DEPENDS+=       ${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx
DEPENDS+=       ${PYPKGPREFIX}-redis-py>=2.8.0:../../wip/py-redis-py

PYTHON_VERSION_DEFAULT= 26 27
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-mysqldb, py-networkx

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
