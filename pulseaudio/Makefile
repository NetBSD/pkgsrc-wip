# $NetBSD: Makefile,v 1.1 2007/01/29 22:07:32 bsadewitz Exp $
#

DISTNAME=	pulseaudio-0.9.5
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/pulseaudio/

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://www.pulseaudio.org/
COMMENT=	The esound replacement everyone's been waiting for

USE_TOOLS+=	pkg-config gmake

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CFLAGS+=	-Wall

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--disable-hal
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-solaris
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_INCDIRS.libX11:Q}
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_LIBDIRS.libX11:Q}

CPPFLAGS+=	-D_NETBSD_SOURCE

BUILD_DEFS+=	VARBASE

PKGCONFIG_OVERRIDE+=	libpulse-browse.pc.in
PKGCONFIG_OVERRIDE+=	libpulse-mainloop-glib.pc.in
PKGCONFIG_OVERRIDE+=	libpulse-simple.pc.in
PKGCONFIG_OVERRIDE+=	libpulse.pc.in

.include "../../devel/GConf2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../devel/libltdl/convenience.mk"
.include "../../devel/liboil/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"

.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
