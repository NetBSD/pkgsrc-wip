# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:22:04 jihbed Exp $
#

DISTNAME=	numpydoc-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/n/numpydoc/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/numpy/numpy/tree/master/doc/sphinxext
COMMENT=	Sphinx extension to support docstrings in Numpy format
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.0.8:../../textproc/py-sphinx

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/numpydoc-0.4

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
