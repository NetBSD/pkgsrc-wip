# $NetBSD: Makefile,v 1.2 2012/10/07 12:25:17 asau Exp $

DISTNAME=	mcview-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mcview/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi?%3Aaction=search&term=mcview&submit=search
COMMENT=	3D/graph event viewer for high-energy physics event simulations
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.4.0

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} mcview mcview-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
