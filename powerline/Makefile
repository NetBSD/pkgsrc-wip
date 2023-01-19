# $NetBSD$

DISTNAME=	powerline-2.8.3
CATEGORIES=	sysutils python
# powerline-status on pypi
MASTER_SITES=	${MASTER_SITE_GITHUB:=powerline/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/powerline/powerline
COMMENT=	Ultimate statusline/prompt utility
LICENSE=	mit

EGG_NAME=	powerline_status-${PKGVERSION_NOREV}

REPLACE_PYTHON+=	powerline/bindings/*.py
REPLACE_PYTHON+=	powerline/bindings/*/*.py

DEPENDS+=	socat-[0-9]*:../../net/socat
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-hglib-[0-9]*:../../devel/py-hglib
DEPENDS+=	${PYPKGPREFIX}-pygit2-[0-9]*:../../devel/py-pygit2
# unpackaged
#DEPENDS+=	${PYPKGPREFIX}-uv-[0-9]*:../../devel/py-uv
DEPENDS+=	xrandr-[0-9]*:../../x11/xrandr
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for f in powerline powerline-config powerline-daemon powerline-lint powerline-render
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ${f} ${f}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
