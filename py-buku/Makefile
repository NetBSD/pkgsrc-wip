# $NetBSD$

DISTNAME=	buku-5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buku/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jarun/buku
COMMENT=	Personal mini-web in text
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-arrow>=1.2.2:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-flasgger-[0-9]*:../../www/py-flasgger
DEPENDS+=	${PYPKGPREFIX}-flask>=2.2.2:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-admin>=2:../../www/py-flask-admin
DEPENDS+=	${PYPKGPREFIX}-flask-babel-[0-9]*:../../www/py-flask-babel
DEPENDS+=	${PYPKGPREFIX}-flask-wtf>=1.0.1:../../www/py-flask-wtf
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-urllib3-[0-9]*:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
#    "flask-paginate>=2022.1.8",

USE_LANGUAGES=	# none

# as of 5.1
# 12 failed, 1104 passed, 6 skipped, 171 warnings, 133 errors

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	cd ${DESTDIR}${PREFIX}/share/man/man1 && ${MV} buku.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/buku.1

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
