# $NetBSD: Makefile,v 1.3 2010/08/01 14:57:09 asau Exp $

DISTNAME=	scipy-0.6.0
PKGNAME=	${PYPKGPREFIX}-scipy-0.6.0
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scipy/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.scipy.org/
COMMENT=	Scientific Algorithms Library for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PLIST_SUBST+=   PYPKGPREFIX=${PYPKGPREFIX}
PYTHON_VERSIONS_ACCEPTED=   25 24
USE_LANGUAGES+=	c c++ fortran77
MAKE_ENV+=	ATLAS=None

.include "../../lang/python/extension.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../wip/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
