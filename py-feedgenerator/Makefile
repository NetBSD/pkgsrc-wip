# $NetBSD: Makefile,v 1.2 2013/08/06 06:39:37 ahp-nils Exp $
#

DISTNAME=		feedgenerator-1.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		www
MASTER_SITES=	https://pypi.python.org/packages/source/f/feedgenerator/
FETCH_USING=	curl
MAINTAINER=		ahp-nils@users.sourceforge.net
HOMEPAGE=		https://github.com/dmdm/feedgenerator-py3k.git
COMMENT=		Standalone version of django.utils.feedgenerator, compatible with Py3k
LICENSE=		modified-bsd

DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../wip/py-six
DEPENDS+=		${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

PYTHON_VERSIONS_INCLUDE_3X= yes
USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
