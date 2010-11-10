# $NetBSD: Makefile,v 1.15 2010/11/10 05:33:54 rxg Exp $
#

DISTNAME=	zinf-2.2.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zinf/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.zinf.org/
COMMENT=	Simple but powerful audio player
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	nasm>=0.98:../../devel/nasm

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake perl pkg-config

LIBTOOL_OVERRIDE=	libtool

CONFIGURE_ARGS+=	--enable-cmdline \
			--enable-ipv6 \
			--enable-corba \
			--enable-xosd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-mp3prof
.endif

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CONFIGURE_ARGS+=	--disable-x86opts
.endif

PRIVILEGED_STAGES+=	clean

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/arts/buildlink3.mk"
.include "../../audio/esound/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/xosd/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
