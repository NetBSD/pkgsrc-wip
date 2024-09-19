# $NetBSD$

CATEGORIES=	games

COMMENT=	Strategy game engine for early Westwood games such as C&C: Red Alert
LICENSE=	gnu-gpl-v3

VERSION=	20161019
PKGNAME=	OpenRA-${VERSION}
DISTNAME=	release-${VERSION}
GITHUB_PROJECT=	OpenRA
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenRA/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	tm@core.io
HOMEPAGE=	https://github.com/OpenRA/OpenRA/

USE_TOOLS+=	gmake unzip
SMF_METHODS=	openra

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

DEPENDS+=	libgdiplus-[0-9]*:../../graphics/libgdiplus
DEPENDS+=	lua51-[0-9]*:../../lang/lua51

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Fix version in Makefile
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	Makefile
SUBST_SED.version=	-e "s,VERSION\ *=.*,VERSION=${DISTNAME},"

SUBST_CLASSES+=		deps
SUBST_MESSAGE.deps=	Modify lookup path for liblua51
SUBST_STAGE.deps=	pre-configure
SUBST_FILES.deps=	thirdparty/configure-native-deps.sh
SUBST_SED.deps=		-e "s,locations=\"\(.*\)\",locations=\"\1 ${PREFIX}/lib\","

.include "../../mk/bsd.prefs.mk"
OPENRA_USER?=	openra
OPENRA_GROUP?=	games
OPENRA_HOME?=	${VARBASE}/games/openra
PKG_GROUPS=	${OPENRA_GROUP}
PKG_USERS=	${OPENRA_USER}:${OPENRA_GROUP}
PKG_GROUPS_VARS=	OPENRA_USER
PKG_USERS_VARS=		OPENRA_GROUP
PKG_HOME.${OPENRA_USER}=	${OPENRA_HOME}


OWN_DIRS+=		${OPENRA_HOME}
OWN_DIRS_PERMS+=	${OPENRA_HOME} ${OPENRA_USER} ${OPENRA_GROUP} 0770

FILES_SUBST+=	OPENRA_USER=${OPENRA_USER}
FILES_SUBST+=	OPENRA_GROUP=${OPENRA_GROUP}

pre-configure:
	cd ${WRKSRC} && gmake dependencies

pre-install:
	cd ${WRKSRC} && \
	gmake prefix=${DESTDIR}${PREFIX} mandir=${DESTDIR}${PREFIX}/${PKGMANDIR} \
	tools docs version

do-install:
	cd ${WRKSRC} && \
	gmake prefix=${DESTDIR}${PREFIX} mandir=${DESTDIR}${PREFIX}/${PKGMANDIR} \
	install install-linux-scripts install-man-page

.include "../../lang/mono/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../graphics/libgdiplus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
