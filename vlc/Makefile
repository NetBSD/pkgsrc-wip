# $NetBSD: Makefile,v 1.2 2003/09/19 21:30:47 thomasklausner Exp $
# This is an experimental package, released in the hope that somebody will find
# why playback is not working properly.

VLC_VERSION=		0.4.6
DISTNAME=		vlc-${VLC_VERSION}
CATEGORIES=		graphics
MASTER_SITES=		http://www.videolan.org/pub/videolan/vlc/${VLC_VERSION}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.videolan.org/
COMMENT=		VideoLan Client

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
HAS_CONFIGURE=		YES
USE_X11=        	# defined
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--prefix="${PREFIX}"
.ifndef notdef
CONFIGURE_ARGS+=	--with-dvdcss="${PREFIX}"
.include "../../misc/libdvdcss/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--enable-dvdread
.include "../../misc/libdvdread/buildlink2.mk"
.endif
CONFIGURE_ARGS+=	--disable-arts
#CONFIGURE_ARGS+=	--disable-vcd
CONFIGURE_ARGS+=	--enable-aa
CONFIGURE_ARGS+=	--enable-esd
CONFIGURE_ARGS+=	--enable-gtk
CONFIGURE_ARGS+=	--enable-gnome
CONFIGURE_ARGS+=	--enable-familiar
CONFIGURE_ARGS+=	--enable-release
CONFIGURE_ARGS+=	--enable-debug

.include "../../mk/bsd.prefs.mk"

#.if ${MACHINE_ARCH} == "i386"
#.if ${VLC_USE_REALMEDIA} == "YES"
#CONFIGURE_ARGS+=	--with-reallibdir="${LOCALBASE}/lib/RealPlayer8/Codecs"
#.endif
#.endif

# .include "../../audio/arts/buildlink2.mk"
.include "../../audio/esound/buildlink2.mk"
.include "../../audio/liba52/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
