# $NetBSD: Makefile,v 1.34 2023/12/11 10:07:09 wiz Exp $

DISTNAME=	urwid-mitmproxy-2.1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urwid-mitmproxy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mitmproxy/urwid-mitmproxy
COMMENT=	Urwid fork with specific patches for mitmproxy
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-exceptiongroup-[0-9]*:../../devel/py-exceptiongroup
TEST_DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado>=5:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-trio-[0-9]*:../../devel/py-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
TEST_DEPENDS+=	${PYPKGPREFIX}-zmq-[0-9]*:../../net/py-zmq

PYTHON_VERSIONS_INCOMPATIBLE=	27

# XXX: This is very dirty and fragile!
SUBST_CLASSES+=			urwid_mitmproxy
SUBST_STAGE.urwid_mitmproxy=	pre-configure
SUBST_MESSAGE.urwid_mitmproxy=	Avoid conflicts with urwid
SUBST_FILES.urwid_mitmproxy=	*/*.py */*/*.py
SUBST_SED.urwid_mitmproxy+=	-e 's/urwid/urwid_mitmproxy/g'

# Avoid conflicts with urwid
post-install:
	${MV} ${DESTDIR}${PREFIX}/${PYSITELIB}/urwid ${DESTDIR}${PREFIX}/${PYSITELIB}/urwid_mitmproxy

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
