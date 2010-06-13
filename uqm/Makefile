# $NetBSD: Makefile,v 1.16 2010/06/13 22:47:21 thomasklausner Exp $
#

DISTNAME=	uqm-0.6.2-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sc2/}
EXTRACT_SUFX=	.tgz
DISTFILES=		${DEFAULT_DISTFILES} uqm-0.6.0-content.uqm

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://sc2.sourceforge.net/
COMMENT=	Ur-Quan Masters
# GPL and Creative Commons Attribution-NonCommercial-ShareAlike 2.5
#LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=		uqm
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
USE_TOOLS=		gmake pkg-config
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}/sc2

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-configure
SUBST_MESSAGE.config=	Fixing config.state...
SUBST_FILES.config=	config.state
SUBST_SED.config+=	-e 's;/usr/local/games;${DESTDIR}${PREFIX};'

INSTALLATION_DIRS=	bin lib share/uqm/content/packages share/doc/uqm

do-configure:
	cd ${WRKSRC} && ./build.sh uqm config

do-build:
	cd ${WRKSRC} && ./build.sh uqm reprocess_config && ./build.sh uqm

do-install:
	cd ${WRKSRC} && ./build.sh uqm install
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/uqm-0.6.0-content.uqm \
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
