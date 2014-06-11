# $NetBSD: Makefile,v 1.3 2014/06/11 22:00:08 jihbed Exp $

DISTNAME=	numpydoc-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/n/numpydoc/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/numpy/numpy/tree/master/doc/sphinxext
COMMENT=	Sphinx extension to support docstrings in Numpy format
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.0.8:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 27 33 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
