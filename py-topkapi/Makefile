# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:47 thomasklausner Exp $

DISTNAME=	PyTOPKAPI-0.2.0
PKGNAME=	${DISTNAME:tl:S/py/${PYPKGPREFIX}-/1}
CATEGORIES=	misc python
MASTER_SITES=	https://github.com/downloads/sahg/PyTOPKAPI/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://sahg.github.com/PyTOPKAPI
COMMENT=	TOPKAPI hydrological model in Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-rpy>=2.1.3:../../math/py-rpy
#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

# pkgsrc is not currently able to fetch distfiles from https web servers
# (see mk/fetch/fetch.mk), so you have to use a browser for now.
FETCH_BEFORE_ARGS=	--no-check-certificate

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
