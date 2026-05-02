# $NetBSD$

DISTNAME=	xeus-python-shell-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/jupyter-xeus/xeus-python-shell
COMMENT=	The xeus-python core python logic
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}
DEPENDS+=	${PYPKGPREFIX}-debugpy<2.0.0:../../devel/py-debugpy

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
