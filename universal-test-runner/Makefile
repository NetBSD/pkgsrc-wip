# $NetBSD$

DISTNAME=	universal-test-runner-0.5.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=xavdid/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xavdid/universal-test-runner/
COMMENT=	Language-agnostic, zero-configuration test invoker
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=8.1.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.6:../../comms/py-colorama

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
