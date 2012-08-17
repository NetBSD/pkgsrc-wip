# $NetBSD: Makefile,v 1.18 2012/08/17 20:06:50 leot1990 Exp $
#

DISTNAME=	uqm-0.7.0-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sc2/}
EXTRACT_SUFX=	.tgz
DISTFILES=		${DEFAULT_DISTFILES} uqm-0.7.0-content.uqm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sc2.sourceforge.net/
COMMENT=	Ur-Quan Masters
# FIXME: GPL and Creative Commons Attribution-NonCommercial-ShareAlike 2.5
#     At the moment cc-by-nc-sa-2.5v-license is not present in
#     pkgsrc/licenses/, this is why LICENSE is commented.
#LICENSE=	gnu-gpl-v2 AND cc-by-nc-sa-2.5v-license

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=		uqm
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
USE_TOOLS=		gmake pkg-config
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

SUBST_CLASSES+=		nomenu
SUBST_STAGE.nomenu=	pre-configure
SUBST_MESSAGE.nomenu=	Make configure process non-interactive.
SUBST_FILES.nomenu=	build/unix/menu_functions
SUBST_SED.nomenu+=	-e 's/read /\#read /'

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-configure
SUBST_MESSAGE.config=	Fixing config.state.
SUBST_FILES.config=	config.state
SUBST_SED.config+=	-e 's;opengl;pure;' # Disable OpenGL support
SUBST_SED.config+=	-e 's;/usr/local/games;${DESTDIR}${PREFIX};'


INSTALLATION_DIRS=	bin lib share/uqm/content/packages share/doc/uqm

do-configure:
	cd ${WRKSRC} && ./build.sh uqm config

do-build:
	cd ${WRKSRC} && ./build.sh uqm reprocess_config && ./build.sh uqm

do-install:
	cd ${WRKSRC} && ./build.sh uqm install
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/uqm-0.7.0-content.uqm \
		${DESTDIR}${PREFIX}/share/uqm/content/packages
	${INSTALL_DATA} ${WRKSRC}/doc/users/manual.txt \
		${DESTDIR}${PREFIX}/share/doc/uqm

.include "../../mk/pthread.buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
