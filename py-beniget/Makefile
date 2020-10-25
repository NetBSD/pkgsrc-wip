# $NetBSD$

VERS=		0.3.0
DISTNAME=	beniget-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/${DISTNAME:S/${VERS}//}/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/serge-sans-paille/beniget/
COMMENT=	Extract semantic information about static Python code
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-gast>=0.2.2:../../wip/py-gast

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
