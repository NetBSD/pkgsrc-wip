# $NetBSD$

DISTNAME=	git-spindle-3.4.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/git-spindle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seveas.github.io/git-spindle
COMMENT=	Command-line interface to GitHub and other central git services
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-docopt>=0.5.0:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-github3.py>=0.9.0:../../wip/py-github3.py
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-whelk>=2.6:../../wip/py-whelk

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
