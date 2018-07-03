# $NetBSD: Makefile,v 1.1 2015/02/20 10:10:36 jihbed Exp $

DISTNAME=	moksha.common-1.2.3
PKGNAME=	${PYPKGPREFIX}-moksha-common-1.2.3
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/moksha.common/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://mokshaproject.net/
COMMENT=	Common components for Moksha
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-decorator>=3.4.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-kitchen>=1.2.1:../../wip/py-kitchen

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 1.2.3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
