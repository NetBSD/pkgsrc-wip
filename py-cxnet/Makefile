# $NetBSD: Makefile,v 1.3 2014/06/01 12:49:40 thomasklausner Exp $

DISTNAME=	cxnet-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cxnet/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://django.arek.uni-obuda.hu/cxnet/doc
COMMENT=	Complex networks in education
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
