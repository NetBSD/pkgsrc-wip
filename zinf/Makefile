# $NetBSD: Makefile,v 1.14 2010/06/13 22:47:22 thomasklausner Exp $
#

DISTNAME=	zinf-2.2.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zinf/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.zinf.org/
COMMENT=	Simple but powerful audio player

#BUILD_DEPENDS+=	nasm>=0.98:../../devel/nasm

PTHREAD_OPTS+=	require

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
#USE_PERL5=	yes

CONFIGURE_ARGS+=--enable-cmdline \
		--disable-alsa \
		--disable-arts \
		--disable-x86opts \
#		--enable-mutex-debug

.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../net/ORBit/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
