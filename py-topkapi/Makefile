# $NetBSD: Makefile,v 1.1.1.1 2011/01/22 13:33:53 jihbed Exp $
#

DISTNAME=	PyTOPKAPI-0.2.0
PKGNAME=	${PYPKGPREFIX}-topkapi-0.2.0
CATEGORIES=	science
MASTER_SITES=	https://github.com/downloads/sahg/PyTOPKAPI/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://sahg.github.com/PyTOPKAPI
COMMENT=	TOPKAPI hydrological model in Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-rpy>=2.1.3:../../math/py-rpy
#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

# pkgsrc is not currently able to fetch distfiles from https web servers
# (see mk/fetch/fetch.mk), so you have to use a browser for now.
FETCH_USING=		wget
FETCH_BEFORE_ARGS=	--no-check-certificate


USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
