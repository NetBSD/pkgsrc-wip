# $NetBSD: Makefile,v 1.1.1.1 2011/01/01 09:54:34 ryo-on Exp $

DISTNAME=	mp3blaster-3.2.5
CATEGORIES=	audio
MASTER_SITES=	http://www.stack.nl/~brama/mp3blaster/src/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://mp3blaster.sourceforge.net/
COMMENT=	MP3 console curses-based player

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		splay-[0-9]*

MAKE_JOBS_SAFE=		yes

PTHREAD_OPTS+=	require
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
CONFIGURE_ARGS+=	--enable-newthreads
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.mp3blaster
PKG_SUPPORTED_OPTIONS+=	esound oss sdl
PKG_SUGGESTED_OPTIONS+=	oss

.if empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--with-esd=yes
.include "../../audio/esound/buildlink3.mk"
.endif

.if empty(PKG_OPTIONS:Moss)
CONFIGURE_ARGS+=	--with-oss=yes
.include "../../mk/oss.buildlink3.mk"
.endif

.if empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--with-sdl=yes
.include "../../devel/SDL/buildlink3.mk"
.endif

.include "../../mk/bsd.options.mk"

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
