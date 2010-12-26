# $NetBSD: Makefile,v 1.15 2010/12/26 05:01:24 davesainty Exp $

PKGNAME=		xmoto-${VERSION}
DISTNAME=		xmoto-${VERSION}-src
CATEGORIES=		games
MASTER_SITES=		http://download.tuxfamily.org/xmoto/xmoto/0.5.3/ \
			${MASTER_SITE_SOURCEFORGE:=xmoto/}
VERSION=		0.5.3

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xmoto.sourceforge.net/
COMMENT=		2D motocross plateform game

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt autoconf automake gmake pkg-config
USE_LANGUAGES=		c c++
CONFIGURE_ENV+=		LIBS="-lGL -lm -pthread"

GNU_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS+=	share/applications

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[1-3].[0-9]*)
GCC_REQD+=		3.4
.endif

# Change the desktop file icon.
SUBST_CLASSES+=			desktop
SUBST_STAGE.desktop=		post-install
SUBST_MESSAGE.desktop=		Fixing the icon location in desktop entry.
SUBST_FILES.desktop=		${DESTDIR}${PREFIX}/share/applications/xmoto.desktop
SUBST_SED.desktop=		-e 's,@DATADIR@,${DESTDIR}${PREFIX}/share/xmoto/,'

pre-install:
	${INSTALL_DATA} ${FILESDIR}/xmoto.desktop ${DESTDIR}${PREFIX}/share/applications

.include "../../x11/libxdg-basedir/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../wip/ode/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
