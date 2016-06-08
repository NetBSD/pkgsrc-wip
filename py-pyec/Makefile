# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:27 asau Exp $
#

DISTNAME=	PyEC-0.2.5
PKGNAME=	${PYPKGPREFIX}-pyec-0.2.5
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyEC/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://nn.cs.utexas.edu/?pyec
COMMENT=	Evolutionary computation package
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

WRKSRC=		${WRKDIR}/PyEC-0.2.5

USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
