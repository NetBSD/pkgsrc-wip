# $NetBSD: Makefile,v 1.4 2013/08/31 21:33:51 jihbed Exp $

DISTNAME=	neurolab-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/n/neurolab/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/neurolab
COMMENT=	Simple and powerfull neural network library for python
LICENSE=	gnu-lgpl-v3

FETCH_USING=    curl

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
