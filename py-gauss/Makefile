# $NetBSD: Makefile,v 1.1 2015/08/01 22:47:56 jihbed Exp $

DISTNAME=	pygauss-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygauss/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/p/pygauss/
COMMENT=	Python API for Analysis of Gaussian Quantum Chemical Compuations
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
