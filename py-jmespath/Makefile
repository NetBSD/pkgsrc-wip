# $NetBSD$

GITHUB_PROJECT=	jmespath.py
DISTNAME=	${GITHUB_PROJECT}-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmespath/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/jmespath/jmespath.py/
COMMENT=	JMESPath is a query language for JSON
LICENSE=	mit

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
