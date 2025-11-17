# $NetBSD: Makefile,v 1.20 2025/01/06 21:49:19 ktnb Exp $

DISTNAME=	xu4-1.4.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=xu4-engine/}
GITHUB_PROJECT=	u4
GITHUB_TAG=	v${PKGVERSION_NOREV}

DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	u4upgrad.zip
EXTRACT_ONLY=	${DEFAULT_DISTFILES}

SITES.u4upgrad.zip= \
	-http://sourceforge.net/projects/xu4/files/Ultima%204%20VGA%20Upgrade/1.3/u4upgrad.zip

#GLV_GITHASH=	20ab75d39ae1ab27c55f1eea09c83b3985738110
#
#DISTFILES=	${DEFAULT_DISTFILES}
#DISTFILES+=	outguard-glv-${GLV_GITHASH}.zip
#
#SITES.outguard-glv-${GLV_GITHASH}.zip= \
#	-https://sourceforge.net/code-snapshots/git/o/ou/outguard/glv.git/outguard-glv-${GLV_GITHASH}.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xu4.sourceforge.net/
COMMENT=	Remake of Ultima IV
LICENSE=	gnu-gpl-v3

DEPENDS+=	timidity-[0-9]*:../../audio/timidity

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run gmake

REPLACE_BASH=	configure
CONFIG_SHELL=	${BASH}

CONFIGURE_ARGS+=	--glfw

INSTALLATION_DIRS+=	share/applications share/doc/xu4 
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps

BORON=	${PREFIX}/bin/boron

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing paths of binaries
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile
SUBST_VARS.paths=	BORON

post-extract:
	${RUN}${CP} ${DISTDIR}/u4upgrad.zip ${WRKSRC}
#	${RUN}${CP} -r ${WRKDIR}/outguard-glv-${GLV_GITHASH}/* ${WRKSRC}/src/glv

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/xu4

.include "../../wip/faun/buildlink3.mk"
.include "../../wip/boron/buildlink3.mk"
.include "../../graphics/glfw/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
