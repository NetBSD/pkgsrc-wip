# $NetBSD: Makefile,v 1.1 2014/05/09 23:11:15 jihbed Exp $

DISTNAME=	bloscpack-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bloscpack/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/esc/bloscpack
COMMENT=	Command line interface to and serialization format for Blosc
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-blosc>=1.2.3:../../wip/py-blosc

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.6.0

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/blpk ${WRKSRC}/blpk${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
