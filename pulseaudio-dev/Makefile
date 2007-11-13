# $NetBSD: Makefile,v 1.1 2007/11/13 23:32:17 bsadewitz Exp $
#

DISTNAME=	pulseaudio-${PULSE_SNAP_VERSION}
CATEGORIES=	audio multimedia
MASTER_SITES=	http://www.pulseaudio.org

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://www.pulseaudio.org
COMMENT=	PulseAudio multimedia/audio daemon

PKG_DESTDIR_SUPPORT=	user-destdir

SPECIAL_PERMS+=		bin/pulseaudio ${SUID_ROOT_PERMS}

NO_SRC_ON_FTP=  	# empty
NO_SRC_ON_CDROM=	# empty

AUTOMAKE_REQD=		1.10
AUTOCONF_REQD=		2.60
GCC_REQD+=		3.4 # XXX verify

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake gmake
USE_TOOLS+=		date gm4
USE_TOOLS+=		pkg-config

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--disable-manpages
CONFIGURE_ARGS+=	--disable-avahi
CONFIGURE_ARGS+=	--disable-jack
CONFIGURE_ARGS+=	--disable-asyncns
CONFIGURE_ARGS+=	--disable-tcpwrap
CONFIGURE_ARGS+=	--disable-lirc
CONFIGURE_ARGS+=	--disable-hal
CONFIGURE_ARGS+=	--disable-bluez

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}

CONFIGURE_ARGS+=	--with-system-user=${PULSE_USER:Q}
CONFIGURE_ARGS+=	--with-system-group=${PULSE_GROUP:Q}
CONFIGURE_ARGS+=	--with-realtime-group=${PULSE_RT_GROUP:Q}
CONFIGURE_ARGS+=	--with-access-group=${PULSE_ACCESS_GROUP:Q}

CFLAGS+=		${PULSE_CPPFLAGS}
CFLAGS+=		${PULSE_CFLAGS}
CFLAGS.NetBSD=		-D_NETBSD_SOURCE

PKGCONFIG_OVERRIDE+=	libpulse-browse.pc.in
PKGCONFIG_OVERRIDE+=	libpulse-mainloop-glib.pc.in
PKGCONFIG_OVERRIDE+=	libpulse-simple.pc.in
PKGCONFIG_OVERRIDE+=	libpulse.pc.in

PKG_USERS=	${PULSE_USER}:${PULSE_GROUP}::PulseAudio\ User:/nonexistent
PKG_GROUPS=	${PULSE_GROUP}

PLIST_SRC=		${WRKDIR}/.PLIST

PULSE_USER=		pulse
PULSE_GROUP=		pulse
PULSE_RT_GROUP=		pulse-rt
PULSE_ACCESS_GROUP=	pulse-ac
PULSE_VERSION=		0.9

REPLACE_SH=		bootstrap.sh autogen.sh

SVN_REPOSITORIES=       pulseaudio
SVN_TAG=                {${PULSE_TAG}}
SVN_ROOT.pulseaudio=    svn://svn.0pointer.de/pulseaudio/trunk
SVN_MODULE.pulseaudio=	pulseaudio

.include "../../mk/bsd.prefs.mk"
.include "../../wip/mk/svn-package.mk"

WRKSRC=			${WRKDIR}/${PKGBASE}

HAVE_TLS_BUILTIN?=		no

.include "options.mk"

USE_FEATURES.pulseaudio+=rtsignals # XXX SIGRT{MIN,MAX}--any others here?
.if ${OPSYS} == "NetBSD"
MISSING_FEATURES+=	rtsignals
.endif

.if defined(MISSING_FEATURES) 
.  if !empty(MISSING_FEATURES:Moss-dsp)
BUILD_PADSP=		\#
.  else
BUILD_PADSP=		# empty
.  endif

.  if !empty(MISSING_FEATURES:Mrtsignals)
BUILD_RTPOLL_TEST=	\#
.  else
BUILD_RTPOLL_TEST=	# empty
.  endif
.endif

.if !empty(HAVE_TLS_BUILTIN:M[Nn][Oo])
SUBST_CLASSES+=		tls
SUBST_FILES.tls+=	config.h
SUBST_STAGE.tls=	post-configure
SUBST_MESSAGE.tls=	Bypassing dumb configure check for thread-local storage.
SUBST_SED.tls+=		-e '/HAVE_TLS_BUILTIN/D'
.endif

SUBST_CLASSES+=		pa_feat
SUBST_FILES.pa_feat=	src/Makefile.am
SUBST_STAGE.pa_feat=	pre-configure
SUBST_MESSAGE.pa_feat=	Disabling build of padsp and/or rtpoll test.
SUBST_VARS.pa_feat=	BUILD_PADSP BUILD_RTPOLL_TEST 

SUBST_CLASSES+=		pa_pc
SUBST_FILES.pa_pc=	*.pc.in
SUBST_MESSAGE.pa_pc=	Privatizing/fixing thread info in .pc files.
SUBST_STAGE.pa_pc=	pre-configure

.if !empty(PKG_OPTIONS:Mthreads)
.  if empty(PTHREAD_CPPFLAGS) && ${OPSYS} == "NetBSD"
PTHREAD_CPPFLAGS=	-D_REENTRANT
.  endif
SUBST_VARS.pa_pc=	PTHREAD_CPPFLAGS PTHREAD_LDFLAGS
.else
SUBST_SED.pa_pc=	-e 's,@PTHREAD_CPPFLAGS@,,'
SUBST_SED.pa_pc+=	-e 's,@PTHREAD_LIBS@,,'
.endif

.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M4.99.[3-9][0-9]) # XXX check
PULSE_CPPFLAGS+=	-DPOSIX_MEMALIGN_IN_JEMALLOC
.endif

YESTERDAY!=     	expr `date +%s` - 86399
PULSE_TAG!=		${DATE} +%Y%m%d
PULSE_SNAP_VERSION!=		${DATE} -r ${YESTERDAY} +%Y%m%d


pre-configure:
	@ if ${TEST} ! -f ${${WRKSRC}/configure:L:Q}; then \
		${ECHO_MSG} "=> Running autoconf for ${PKGBASE}.";	\
		cd ${WRKSRC} && \
		${TOUCH} config.rpath && \
		${SETENV} NO_CONFIGURE=1 autoreconf -vi; \
	fi

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/liboil/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
