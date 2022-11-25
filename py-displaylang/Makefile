# $NetBSD$

DISTNAME=	displaylang-0.22.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/displaylang/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/proofscape/displaylang
COMMENT=	Just enough Python to write displays
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-typeguard>=2.13.3:../../devel/py-typeguard
#DEPENDS+=	${PYPKGPREFIX}-pfsc-util>=0.22.8:../../wip/py-pfsc-util


USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
