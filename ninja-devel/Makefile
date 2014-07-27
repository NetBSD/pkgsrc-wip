# $NetBSD: Makefile,v 1.2 2014/07/27 06:28:21 makoto Exp $
#
DISTNAME=		ninja-1.5.1
CATEGORIES=		devel
MASTER_SITES=		https://github.com/martine/ninja

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://martine.github.io/ninja/
COMMENT=		Ninja is a small build system with a focus on speed
LICENSE=		apache-2.0

BUILD_DEPENDS+=		re2c-[0-9]*:../../devel/re2c

GIT_REPOSITORIES=	ninja
GIT_MODULE.ninja=	ninja
GIT_TAG.ninja=		release
GIT_REPO.ninja=		https://github.com/martine/ninja
GIT_FLAGS?=		--depth 1

USE_LANGUAGES+=		c c++
USE_TOOLS+=		cmake
AUTO_MKDIRS=		yes

WRKSRC=			${WRKDIR}/${PKGBASE}

pre-configure:
	(cd ${WRKSRC}; ./bootstrap.py)

do-install:
	(cd ${WRKSRC};	\
	${INSTALL} ninja  ${DESTDIR}${PREFIX}/bin )

# ${PREFIX}/bin/ninja -h for help

do-build:
	${NADA}

.include "../../wip/mk/git-package.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
