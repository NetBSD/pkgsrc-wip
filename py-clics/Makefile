# $NetBSD: Makefile,v 1.6 2014/05/09 07:38:46 thomasklausner Exp $

DISTNAME=	CLICS-src-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/CLICS/clics/S/-src//}
CATEGORIES=	devel python
MASTER_SITES=	http://coryk.afraid.org/downloads/CLICS/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.swag.uwaterloo.ca/
COMMENT=	Clone detector and GUI
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.2.2:../../databases/py-psycopg2

WRKSRC=			${WRKDIR}/CLICS-d93a40ceebaa

USE_PKGLOCALEDIR=		yes
USE_LANGUAGES=			c c++
PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-wxWidgets

INSTALLATION_DIRS=	# blank

.include "../../lang/python/extension.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
