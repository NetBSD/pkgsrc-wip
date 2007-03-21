# $NetBSD: Makefile,v 1.3 2007/03/21 20:21:06 bsadewitz Exp $

DISTNAME=		jack-audio-connection-kit-0.103.0
PKGNAME=		jack-0.103.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jackit/}

MAINTAINER=		blair.sadewitz@gmail.com
HOMEPAGE=		http://jackaudio.org/
COMMENT=		Low-latency audio server

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
LIBTOOLIZE_PLIST=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	jack.pc.in

CPPFLAGS+=		-DOSS_DRIVER_DEF_DEV="\"${DEVOSSAUDIO}\"" -Wall

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
