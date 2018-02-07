# $NetBSD: Makefile,v 1.1 2015/08/02 22:19:29 jihbed Exp $

DISTNAME=	EasyModeler-2.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=E/EasyModeler/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/EasyModeler
COMMENT=	Simple ODE Tools for Modelers
ICENSE=		modified-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
#DEPENDS+=	${PYPKGPREFIX}-sas7bdat>=2.0.4:../../wip/py-sas7bdat

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
