# $NetBSD: Makefile,v 1.41 2023/11/07 22:38:02 wiz Exp $

DISTNAME=	streamlink-7.1.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=streamlink/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://streamlink.github.io/
COMMENT=	Tool that pipes video streams into a video player
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-country-[0-9]*:../../geography/py-country
DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.4.3:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup-[0-9]*:../../devel/py-exceptiongroup
DEPENDS+=	${PYPKGPREFIX}-isodate-[0-9]*:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-Socks>=1.5.6:../../net/py-Socks
DEPENDS+=	${PYPKGPREFIX}-requests>=2.26.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-trio-[0-9]*:../../devel/py-trio
DEPENDS+=	${PYPKGPREFIX}-trio-websocket-[0-9]*:../../wip/py-trio-websocket
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=1.2.1:../../www/py-websocket-client
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioningit>=1.1.1:../../devel/py-versioningit
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=45:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-import-order-[0-9]*:../../devel/py-flake8-import-order
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=1.0.0:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock-[0-9]*:../../devel/py-requests-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/flv.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/tag.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/__init__.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/packet.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/error.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/f4v.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/util.py
REPLACE_PYTHON+=	src/streamlink/plugins/tv3cat.py
REPLACE_PYTHON+=	src/streamlink/plugins/tvplayer.py

# as of 4.0.1
# 1 failed, 4591 passed, 31 skipped
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
