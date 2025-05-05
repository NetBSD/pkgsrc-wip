# $NetBSD$

DISTNAME=	gn-0.0.0
CATEGORIES=	devel
GIT_REPO=	https://gn.googlesource.com/gn

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gn.googlesource.com/gn/
COMMENT=	Meta-build system that generates build files for Ninja
LICENSE=	modified-bsd

TOOL_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

USE_LANGUAGES=		c c++
INSTALLATION_DIRS+=	bin

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON} build/gen.py

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/ninja -j ${_MAKE_JOBS_N} -C out

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./out/gn_unittests

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/gn ${DESTDIR}${PREFIX}/bin


.include "../../lang/python/tool.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
