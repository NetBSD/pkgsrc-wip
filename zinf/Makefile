# $NetBSD: Makefile,v 1.3 2003/08/29 11:49:28 thomasklausner Exp $
#

DISTNAME=	zinf-2.2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zinf/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.zinf.org/
COMMENT=	Simple but powerful audio player

#BUILD_DEPENDS+=	nasm>=0.98:../../devel/nasm

PTHREAD_OPTS=	require

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
#USE_PERL5=	yes

CONFIGURE_ARGS+=--enable-cmdline \
		--disable-alsa \
		--disable-arts \
		--disable-x86opts \
#		--enable-mutex-debug

.include "../../audio/musicbrainz/buildlink2.mk"
.include "../../audio/esound/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../net/ORBit/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/x11.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
