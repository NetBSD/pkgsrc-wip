# $NetBSD$

DISTNAME=	Mopidy-3.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Mopidy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mopidy.com/
COMMENT=	Extensible music server written in Python
LICENSE=	apache-2.0

DEPENDS+=	gst-plugins1-base-[0-9]*:../../multimedia/gst-plugins1-base
DEPENDS+=	gst-plugins1-good-[0-9]*:../../multimedia/gst-plugins1-good
DEPENDS+=	gst-plugins1-ugly-[0-9]*:../../multimedia/gst-plugins1-ugly
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-gstreamer1-[0-9]*:../../multimedia/py-gstreamer1
DEPENDS+=	${PYPKGPREFIX}-pykka-[0-9]*:../../devel/py-pykka
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/mopidy ${DESTDIR}${PREFIX}/bin/mopidy-${PYVERSSUFFIX} || ${TRUE}

# as of 3.4.1
# 10 failed, 1431 passed, 5 skipped, 1 warning
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
