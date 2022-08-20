# $NetBSD$

DISTNAME=	elastic-transport-${GITHUB_RELEASE:S/v//}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=elastic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/elastic/${GITHUB_PROJECT}
COMMENT=	Transport classes and utilities for Elastic client libraries

GITHUB_PROJECT=	elastic-transport-python
GITHUB_RELEASE=	v8.1.2

LICENSE=	apache-2.0

EGG_NAME=	${DISTNAME:S/-py//}

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
