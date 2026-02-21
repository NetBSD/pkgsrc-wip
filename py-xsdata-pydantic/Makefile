# $NetBSD$

DISTNAME=	xsdata-pydantic-24.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tefra/}
GITHUB_PROJECT=	xsdata-pydantic
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/tefra/xsdata-pydantic/
COMMENT=	xsdata powered by pydantic
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.6:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-xsdata>=24.5:../../wip/py-xsdata

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
