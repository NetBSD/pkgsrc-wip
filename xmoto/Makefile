# $NetBSD: Makefile,v 1.17 2014/08/09 18:33:51 nros Exp $

PKGNAME=		xmoto-${VERSION}
DISTNAME=		xmoto-${VERSION}-src
CATEGORIES=		games
MASTER_SITES=		http://download.tuxfamily.org/xmoto/xmoto/${VERSION}/ \
			${MASTER_SITE_SOURCEFORGE:=xmoto/}
VERSION=		0.5.11

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xmoto.tuxfamily.org/
COMMENT=		2D motocross platform game
LICENSE=		gnu-gpl-v2


USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gmake pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

PTHREAD_OPTS+=		require

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[1-3].[0-9]*)
GCC_REQD+=		3.4
.endif

pre-configure:
	cd ${WRKSRC} && autoconf

INSTALLATION_DIRS+=	share/applications share/pixmaps

post-install:
	${INSTALL_DATA} ${WRKSRC}/extra/xmoto.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/extra/xmoto.xpm ${DESTDIR}${PREFIX}/share/pixmaps

.include "options.mk"

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/ode/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxdg-basedir/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
