# $NetBSD$

DISTNAME=	marionette_driver-3.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=m/marionette_driver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.mozilla.org/Auto-tools/Projects/Marionette
COMMENT=	Marionette Driver
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-mozrunner>=7.4.0:../../wip/py-mozrunner
DEPENDS+=	${PYPKGPREFIX}-mozversion>=2.1.0:../../wip/py-mozversion
DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
