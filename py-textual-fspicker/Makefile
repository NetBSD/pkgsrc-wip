# $NetBSD$

DISTNAME=	textual_fspicker-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=t/textual_fspicker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://textual-fspicker.davep.dev/
COMMENT=	Simple Textual filesystem picker dialog library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.8.11:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-textual>=1.0.0:../../comms/py-textual

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
