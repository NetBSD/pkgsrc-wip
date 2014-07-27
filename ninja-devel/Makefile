# $NetBSD: Makefile,v 1.3 2014/07/27 07:42:37 makoto Exp $
#
DISTNAME=		ninja-1.5.1
PKGNAME=		${DISTNAME:C/-/-devel-/}
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

# following is effective only after do-install (?)
# REPLACE_PYTHON=		bootstrap.py

USE_LANGUAGES+=		c c++
USE_TOOLS+=		cmake
AUTO_MKDIRS=		yes

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Replace shebang before bootstrap
SUBST_FILES.python=	bootstrap.py
SUBST_STAGE.python=	pre-configure
SUBST_SED.python=	's|/usr/bin/env python|${PREFIX}/bin/python${PYVERSSUFFIX}|'

WRKSRC=			${WRKDIR}/ninja

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
