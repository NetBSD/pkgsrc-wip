# $NetBSD: Makefile,v 1.1 2014/05/09 23:11:15 jihbed Exp $

DISTNAME=	bloscpack-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bloscpack/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/esc/bloscpack
COMMENT=	Command line interface to and serialization format for Blosc
LICENSE=	mit

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYDISTUTILSPKG=	yes

post-extract:
	${MV} ${WRKSRC}/blpk ${WRKSRC}/blpk${PYVERSSUFFIX}


.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-blosc>=1.2.3:../../wip/py-blosc
.include "../../mk/bsd.pkg.mk"
