# $NetBSD$

DISTNAME=	textblob-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=t/textblob/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://textblob.readthedocs.io/
COMMENT=	Python library for processing textual data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nltk>=0:../../wip/py-nltk

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
