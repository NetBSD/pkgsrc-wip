# $NetBSD: Makefile,v 1.5 2012/10/07 12:25:35 asau Exp $
#

VERSION=	0.37
DISTNAME=	OpenOpt
EGG_NAME=	openopt-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://openopt.org/images/3/33/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://openopt.org/Welcome
COMMENT=	Python module for numerical optimization
LICENSE=	modified-bsd

USE_LANGUAGES=	fortran
PYTHON_VERSIONS_ACCEPTED= 26
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
