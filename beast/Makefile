# $NetBSD: Makefile,v 1.5 2004/08/17 18:26:14 tvierling Exp $
#

DISTNAME=	beast-0.5.4
CATEGORIES=	audio
MASTER_SITES=	http://beast.gtk.org/beast-ftp/v0.5/

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://beast.gtk.org/
COMMENT=	Bedevilled Audio System

AUTOCONF_REQD=	2.13

USE_BUILDLINK3=	yes
USE_X11=	yes
USE_LIBTOOL=	yes
LIBTOOL_LA_FILES+=	lib/bse/v0.5.4/plugins/bseadder.la
LIBTOOL_LA_FILES+=	lib/bse/v0.5.4/plugins/bseatandistort.la
LIBTOOL_LA_FILES+=	lib/bse/v0.5.4/plugins/bseiirfilter.la
LIBTOOL_LA_FILES+=	lib/bse/v0.5.4/plugins/bsemixer.la
LIBTOOL_LA_FILES+=	lib/bse/v0.5.4/plugins/bsemult.la
LIBTOOL_LA_FILES+=	lib/bse/v0.5.4/plugins/bsenoise.la
LIBTOOL_LA_FILES+=	lib/bse/v0.5.4/plugins/bsesequencer.la
LIBTOOL_LA_FILES+=	lib/bse/v0.5.4/plugins/bsesimpleadsr.la
LIBTOOL_LA_FILES+=	lib/bse/v0.5.4/plugins/davorgan.la
LIBTOOL_LA_FILES+=	lib/bse/v0.5.4/plugins/davsyndrum.la
LIBTOOL_LA_FILES+=	lib/bse/v0.5.4/plugins/davxtalstrings.la
LIBTOOL_LA_FILES+=	lib/bse/v0.5.4/plugins/freeverb.la
LIBTOOL_LA_FILES+=	lib/libbse.la
LIBTOOL_LA_FILES+=	lib/libbsw.la
LIBTOOL_LA_FILES+=	lib/libsfi.la
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes

LDFLAGS+=	${LIBOSSAUDIO}

pre-configure:
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/autoconf.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
