# $NetBSD: Makefile,v 1.4 2008/01/28 21:30:19 bsadewitz Exp $
#

DISTNAME=	jack-audio-connection-kit-0.109.0
PKGNAME=	${DISTNAME:S/-audio-connection-kit//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jackit/}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://jackit.sourceforge.net/
COMMENT=	Low-latency audio server

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	 	yes
USE_LIBTOOL= 	 	yes
USE_PKGLOCALEDIR= 	yes
USE_TOOLS+= 	 	gmake perl pkg-config

CONFIGURE_ENV+=         ac_cv_header_readline_chardefs_h=yes
CONFIGURE_ENV+= 	ac_cv_lib_readline_readline=yes
CONFIGURE_ENV+= 	ac_cv_func_pthread_create=yes
PKGCONFIG_OVERRIDE+=	jack.pc.in

BROKEN_READLINE_DETECTION= 	yes
DLOPEN_REQUIRE_PTHREADS=	yes

PTHREAD_OPTS+=		require

.if !exists(/dev/shm)
CONFIGURE_ARGS+=	--with-default-tmpdir=/tmp
.endif

.include "../../mk/bsd.prefs.mk"

.include "../../mk/pthread.builtin.mk"

.if !empty(BUILTIN_LIB_FOUND.rt)
LIBS+=		-lrt
LIBS.pc=	-lrt
.endif

.if !empty(PTHREAD_CPPFLAGS)
CFLAGS.pc=	${PTHREAD_CPPFLAGS}
.else
CFLAGS.pc=	-D_REENTRANT
.endif

### XXX This conditional should evaluate as true if poll(2) behaves
###	as it does on Linux.  At least on NetBSD, poll(2) will return
###	POLLIN instead of POLLHUP if the socket is closed.  From FreeBSD
###	ports.
###
.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly"
CPPFLAGS+=	-DPOLLIN_ON_CLOSE
.endif

.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--disable-alsa
.endif

CONFIGURE_ARGS+=	--disable-freebob
CONFIGURE_ARGS+=	--disable-firewire
###
### XXX Code could be written for jackstart.c to use other methods
###	to grant privileges for setting priorities ...
###
CONFIGURE_ARGS+=	--disable-capabilities

.include "../../mk/oss.buildlink3.mk"

.if defined(DEVOSSAUDIO)
CPPFLAGS+=		-DOSS_DRIVER_DEF_DEV=\"${DEVOSSAUDIO}\"
.endif

MAKE_ENV+=		DIGEST=${TOOLS_PATH.digest:Q}

SUBST_CLASSES+= 	pc
SUBST_FILES.pc=	 	jack.pc.in
SUBST_MESSAGE.pc= 	Adding appropriate flags to jack.pc.in.
SUBST_STAGE.pc= 	pre-configure
SUBST_VARS.pc= 	 	CFLAGS.pc LIBS.pc PTHREAD_LDFLAGS PTHREAD_LIBS

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
