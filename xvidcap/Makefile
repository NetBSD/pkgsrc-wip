# $NetBSD: Makefile,v 1.2 2004/05/10 13:45:02 thomasklausner Exp $
#

DISTNAME=		xvidcap-1.1.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xvidcap/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xvidcap.sourceforge.net/
COMMENT=		Capture X display to individual frames or MPEG video

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes # needed for ffmpeg/ code

# XXX later use multimedia/ffmpeg package
# XXX "bundled for now due to color space conversion problems with 0.4.6."
CONFIGURE_ARGS+=	--with-forced-embedded-ffmpeg

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
