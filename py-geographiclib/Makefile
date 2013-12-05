# $NetBSD: Makefile,v 1.1 2013/12/05 22:51:19 jihbed Exp $

DISTNAME=	geographiclib-1.31
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	https://pypi.python.org/packages/source/g/geographiclib/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://geographiclib.sourceforge.net/
COMMENT=	Translation of the GeographicLib::Geodesic class to Python
LICENSE=	mit

WRKSRC=		${WRKDIR}/geographiclib-1.31

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
