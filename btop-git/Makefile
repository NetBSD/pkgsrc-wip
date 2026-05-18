# $NetBSD$

DISTNAME=	btop-1.4.7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=aristocratos/}
GITHUB_TAG=	6e39144aaf5a6bc01b9f795010b0914431067183

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aristocratos/btop
COMMENT=	Colorful TTY resource monitor
LICENSE=	apache-2.0

GIT_REPO=      https://github.com/aristocratos/btop.git

# gcc 10 support was removed from the code base.
# https://github.com/aristocratos/btop/pull/1106
GCC_REQD+=	14

TOOL_DEPENDS+=	lowdown-[0-9]*:../../textproc/lowdown

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

USE_CXX_FEATURES+=	c++20

INSTALLATION_DIRS=	${PKGMANDIR}/man1

CXXFLAGS+=	-DNDEBUG
MAKE_ENV+=	STRIP=false VERBOSE=true DEBUG=true

SUBST_CLASSES+=		themes
SUBST_SED.themes+=	-e 's,/usr/local/share/btop/themes,${PREFIX}/share/btop/themes,'
SUBST_SED.themes+=	-e 's,/usr/.local/.share/btop/themes,${PREFIX}/share/btop/themes,'
SUBST_FILES.themes+=	src/btop_menu.cpp
SUBST_FILES.themes+=	src/btop.cpp
SUBST_STAGE.themes=	pre-configure
SUBST_MESSAGE.themes=	Fixing hardcoded paths to themes.

post-extract:
	# Fix permission issues.
	${CHMOD} -R g-w ${WRKSRC}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
