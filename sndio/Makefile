# $NetBSD$

DISTNAME=	sndio-1.10.0
CATEGORIES=	audio
MASTER_SITES=	http://www.sndio.org/

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	http://www.sndio.org/
COMMENT=	Small audio and MIDI framework
LICENSE=	isc

HAS_CONFIGURE=	yes

USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE=		libsndio/sndio.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

RCD_SCRIPTS=	sndio

SNDIO_USER=	_sndio
SNDIO_GROUP=	_sndio

PKG_USERS=			${SNDIO_USER}:${SNDIO_GROUP}
PKG_GROUPS=			${SNDIO_GROUP}
PKG_GECOS.${SNDIO_USER}=	Sndio user


.include "../../mk/bsd.pkg.mk"
