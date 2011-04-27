# $NetBSD: Makefile,v 1.1.1.1 2011/04/27 22:16:55 jihbed Exp $
#

DISTNAME=	neurolab-0.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	science python
MASTER_SITES=	http://pypi.python.org/packages/source/n/neurolab/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/neurolab
COMMENT=	Simple and powerfull neural network library for python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
