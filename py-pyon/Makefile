# $NetBSD: Makefile,v 1.1 2014/04/29 20:32:43 jihbed Exp $

DISTNAME=	pyon-0.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/p/pyon/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/p/pyon/
COMMENT=	Lattice QCD library including statistical, fitting, plotting functions
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.3.2:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7.2:../../textproc/py-jinja2 

PYTHON_VERSIONS_INCOMPATIBLE=	26 27

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
