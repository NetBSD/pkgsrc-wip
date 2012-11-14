# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:15 othyro Exp $
#

DISTNAME=	neurolab-0.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	http://pypi.python.org/packages/source/n/neurolab/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/neurolab
COMMENT=	Simple and powerfull neural network library for python

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
