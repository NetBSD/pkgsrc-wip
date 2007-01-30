# $NetBSD: Makefile,v 1.2 2007/01/30 03:13:24 bsadewitz Exp $
#

DISTNAME=	pulseaudio-0.9.5
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/pulseaudio/

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://www.pulseaudio.org/
COMMENT=	The esound replacement everyone's been waiting for

#CONFLICTS=	esound-[0-9]*

USE_TOOLS+=	pkg-config gmake

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CFLAGS+=	-Wall

DL_AUTO_VARS=		yes
PTHREAD_AUTO_VARS=	yes

PULSE_CONFDIR=		${PREFOX}/share/examples

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--disable-hal
CONFIGURE_ARGS+=	--disable-avahi
CONFIGURE_ARGS+=	--disable-lirc
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-solaris
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_INCDIRS.libX11:Q}
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_LIBDIRS.libX11:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PULSE_CONFDIR:Q}

#SUPPORT_FILES=		${PULSE_CONFDIR}/default.pa
#CONF_FILES=		${PULSE_CONFDIR}/daemon.conf
#CONF_FILES+=		${PULSE_CONFDIR}/client.conf

CHECK_BUILTIN.oss:=	yes
.include "../../mk/oss.builtin.mk"
CHECK_BUILTIN.oss:=	no
.if !empty(IS_BUILTIN.oss:M[Yy][Ee][Ss])
.include "../../mk/oss.buildlink3.mk"
OSS_LDFLAGS=${BUILDLINK_LDADD.oss:Q}
MAKE_ENV+=	OSS_LDFLAGS=${BUILDLINK_LDADD.oss:Q}
.endif

CPPFLAGS+=	-D_NETBSD_SOURCE

BUILD_DEFS+=	VARBASE

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_MESSAGE.fix-paths= Fixing gnome pathnames in ${SUBST_FILES.fix-paths}.
SUBST_FILES.fix-paths=	src/daemon/default.pa.in
SUBST_SED.fix-paths=	-e 's,/usr/share,${PREFIX}/gnome/share,g'

PKGCONFIG_OVERRIDE+=	libpulse-browse.pc.in
PKGCONFIG_OVERRIDE+=	libpulse-mainloop-glib.pc.in
PKGCONFIG_OVERRIDE+=	libpulse-simple.pc.in
PKGCONFIG_OVERRIDE+=	libpulse.pc.in

.include "../../devel/libltdl/convenience.mk"
.include "../../devel/liboil/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"

.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
