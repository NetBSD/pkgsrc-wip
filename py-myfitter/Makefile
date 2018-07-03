# $NetBSD: Makefile,v 1.2 2014/12/31 13:58:35 thomasklausner Exp $

DISTNAME=	myFitter-python-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//:tl}
CATEGORIES=	math python
MASTER_SITES=	http://www.hepforge.org/archive/myfitter/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://myfitter.hepforge.org/
COMMENT=	Maximum Likelihood Fits in Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.1.3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
