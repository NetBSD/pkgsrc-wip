# $NetBSD: Makefile,v 1.3 2014/09/30 10:58:09 fhajny Exp $

DISTNAME=	pykit-sci-0.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME:S/-/_/}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/p/pykit-sci/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/androomerrill/pykit-sci
COMMENT=	Collection of python modules for science
LICENSE=	2-clause-bsd

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-pint>=0.5:../../wip/py-pint
.include "../../mk/bsd.pkg.mk"
