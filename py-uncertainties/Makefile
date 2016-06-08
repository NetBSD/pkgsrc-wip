# $NetBSD: Makefile,v 1.6 2014/01/12 09:43:46 thomasklausner Exp $

DISTNAME=	uncertainties-2.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uncertainties/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/uncertainties/
COMMENT=	Support for physical quantities with units, based on numpy
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
