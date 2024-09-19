# $NetBSD$

DISTNAME=	proselint-0.10.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=amperser/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://proselint.com/
COMMENT=	Linter for prose
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-future>=0:../../devel/py-future

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
