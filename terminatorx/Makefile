# $NetBSD: Makefile,v 1.2 2004/05/07 01:58:15 xtraeme Exp $
#

DISTNAME=	terminatorX-3.81
PKGNAME=	${DISTNAME:S/X/x/}
CATEGORIES=	audio
MASTER_SITES=	http://terminatorx.cx/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://terminatorx.cx/
COMMENT=	Realtime audio synthesizer

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123
DEPENDS+=	sox-[0-9]*:../../audio/sox
DEPENDS+=	vorbis-tools-[0-9]*:../../audio/vorbis-tools

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBS+=			${LIBOSSAUDIO}
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-scheduler
CONFIGURE_ARGS+=	--disable-lrdf

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../wip/ladspa/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
