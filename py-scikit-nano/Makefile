# $NetBSD: Makefile,v 1.1 2014/01/11 23:18:21 jihbed Exp $

DISTNAME=	scikit-nano-0.2.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	scikit_nano
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/s/scikit-nano/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/androomerrill/scikit-nano
COMMENT=	Python toolkit for generating nano-structures
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-pykit-sci>=0.1.6:../../wip/py-pykit-sci
DEPENDS+=	${PYPKGPREFIX}-pykit-shared>=0.1.9:../../wip/py-pykit-shared
.include "../../mk/bsd.pkg.mk"
