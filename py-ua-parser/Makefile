# $NetBSD$

DISTNAME=	ua-parser-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/ua-parser/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/ua-parser/uap-python/
COMMENT=	Python implementation of the UA Parser
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../lang/python/egg.mk"
WRKSRC=		${WRKDIR}/ua-parser-0.8.0
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
