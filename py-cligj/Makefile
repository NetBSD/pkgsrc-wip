# $NetBSD: Makefile,v 1.1 2015/08/05 20:59:38 jihbed Exp $

DISTNAME=	cligj-0.2.0
 PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cligj/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/mapbox/cligj
COMMENT=	Click params for commmand line interfaces to GeoJSON
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=4.1:../../devel/py-click

WRKSRC=		${WRKDIR}/cligj-0.2.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
