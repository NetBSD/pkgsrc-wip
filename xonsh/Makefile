# $NetBSD$

DISTNAME=	xonsh-0.4.0
CATEGORIES=	shells python
MASTER_SITES=	${MASTER_SITE_GITHUB:=xonsh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xon.sh/
COMMENT=	Python-ish, BASHwards-looking shell language and command prompt
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit-[0-9]*:../../wip/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
