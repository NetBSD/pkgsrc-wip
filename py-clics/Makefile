# $NetBSD: Makefile,v 1.1.1.1 2011/01/24 09:31:55 jihbed Exp $
#

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
DEPENDS+=	${PYPKGPREFIX}-psyco>=1.6:../../lang/py-psyco

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/CLICS-d93a40ceebaa

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	

.include "../../lang/python/extension.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
