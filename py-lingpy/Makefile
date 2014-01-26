# $NetBSD: Makefile,v 1.2 2014/01/26 15:49:58 thomasklausner Exp $

DISTNAME=	lingpy-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/l/lingpy/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/l/lingpy/
COMMENT=	Python library for automatic tasks in historical linguistics
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-regex-[0-9]*:../../wip/py-regex

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-networkx

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
