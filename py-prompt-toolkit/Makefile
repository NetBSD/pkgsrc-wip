# $NetBSD$

DISTNAME=	prompt_toolkit-1.0.3
PKGNAME=	${PYPKGPREFIX}-prompt-toolkit-1.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prompt_toolkit/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jonathanslenders/python-prompt-toolkit
COMMENT=	Library for building powerful interactive command lines
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.1.7:../../wip/py-wcwidth

WRKSRC=		${WRKDIR}/prompt_toolkit-1.0.3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
