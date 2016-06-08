# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:41 thomasklausner Exp $

DISTNAME=	geographiclib-1.31
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geographiclib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://geographiclib.sourceforge.net/
COMMENT=	Translation of the GeographicLib::Geodesic class to Python
LICENSE=	mit

WRKSRC=		${WRKDIR}/geographiclib-1.31

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
