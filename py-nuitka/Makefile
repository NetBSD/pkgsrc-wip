# $NetBSD: Makefile,v 1.1 2015/08/01 22:15:24 jihbed Exp $

DISTNAME=	Nuitka-0.5.13.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=N/Nuitka/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://nuitka.net
COMMENT=	Python compiler with full language support and CPython
LICENSE=	apache-2.0

USE_LANGUAGES=	c++

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # 0.5.13.4 includes and installs old scons version

post-extract:
	${MV} ${WRKSRC}/bin/nuitka  ${WRKSRC}/bin/nuitka${PYVERSSUFFIX}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
