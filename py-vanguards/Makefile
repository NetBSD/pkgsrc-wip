# $NetBSD$

DISTNAME=	vanguards-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mikeperry-tor/}
GITHUB_PROJECT=	vanguards
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mikeperry-tor/vanguards/
COMMENT=	Vanguards Onion Service Addon
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-stem-[0-9]*:../../wip/py-stem

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-pluggy-[0-9]*:../../devel/py-pluggy
TEST_DEPENDS+=	${PYPKGPREFIX}-py-[0-9]*:../../devel/py-py

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"

.if ${PYVERSSUFFIX} == "2.7"
DEPENDS+=	${PYPKGPREFIX}-ipaddress-[0-9]*:../../net/py-ipaddress
TEST_DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
