# $NetBSD$

DISTNAME=	sndio-1.10.0
CATEGORIES=	audio
MASTER_SITES=	http://www.sndio.org/

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	http://www.sndio.org/
COMMENT=	Small audio and MIDI framework
LICENSE=	isc

HAS_CONFIGURE=	yes

RCD_SCRIPTS=	sndio

PKG_USERS=		_sndio:_sndio
PKG_GROUPS=		_sndio
PKG_GECOS._sndio=	Sndio user
PKG_SHELL._sndio=	${NOLOGIN}
PKG_HOME._sndio=	/nonexistent

PKGCONFIG_OVERRIDE=		libsndio/sndio.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Point to the correct OSS device.
SUBST_FILES.oss+=	libsndio/sio_oss.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--pkgconfdir=${PREFIX}/lib/pkgconfig

BUILD_DIRS+=		libsndio sndiod sndioctl aucat midicat

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
