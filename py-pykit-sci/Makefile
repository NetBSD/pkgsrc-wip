# $NetBSD: Makefile,v 1.1 2014/01/11 22:34:29 jihbed Exp $

DISTNAME=	pykit-sci-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/p/pykit-sci/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	 http://github.com/androomerrill/pykit-sci
COMMENT=	Collection of python modules for science
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-pint>=0.4:../../wip/py-pint
DEPENDS+=	${PYPKGPREFIX}-pykit-shared>=0.1.9:../../wip/py-pykit-shared
.include "../../mk/bsd.pkg.mk"
