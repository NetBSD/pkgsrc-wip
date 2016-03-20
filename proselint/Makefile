# $NetBSD$

DISTNAME=	proselint-0.4.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=amperser/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://proselint.com/
COMMENT=	Linter for prose
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-future>=0:../../wip/py-future

USE_LANGUAGES=	# none

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_MESSAGE.version=	Adjust the version number.
SUBST_FILES.version=	proselint/version.py
SUBST_SED.version=	-e 's/0\.4\.0/0.4.2/g'

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
