# $NetBSD: Makefile,v 1.1 2015/06/09 23:08:01 jihbed Exp $

DISTNAME=	bxa-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bxa/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/JohannesBuchner/BXA/
COMMENT=	Bayesian X-ray spectral analysis


DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
