# $NetBSD: Makefile,v 1.5 2014/06/01 12:49:43 thomasklausner Exp $

DISTNAME=	neurolab-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/neurolab/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/neurolab
COMMENT=	Simple and powerfull neural network library for python
LICENSE=	gnu-lgpl-v3


USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
