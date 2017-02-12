# $NetBSD$

DISTNAME=	guessit-2.1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guessit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://guessit.io/
COMMENT=	Extracts as much information as possible from a video filename
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-babelfish>=0.5.5:../../wip/py-babelfish
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-rebulk>=0.8.2:../../wip/py-rebulk

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
