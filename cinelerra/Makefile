# $NetBSD: Makefile,v 1.1.1.1 2004/06/10 07:40:37 jeremy-c-reed Exp $
#

#DISTNAME=		cinelerra-1.2.0-src
DISTNAME=		hvirtual_1.2.0-2cvs20040608
PKGNAME=		cinelerra-1.2.0-2cvs20040608
CATEGORIES=		multimedia
# unofficial source is here
MASTER_SITES=		http://www.kiberpipa.org/~minmax/cinelerra/builds/sid/
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heroines/}
#EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
#HOMEPAGE=		http://heroines.sourceforge.net/
HOMEPAGE=		http://cvs.cinelerra.org/
COMMENT=		Non-linear video and audio editor and compositor (unofficial)

#WRKSRC=			${WRKDIR}/cinelerra-1.2.0/cinelerra
#WRKSRC=			${WRKDIR}/cinelerra-1.2.0
WRKSRC=			${WRKDIR}/hvirtual
USE_X11=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../audio/liba52/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"

# maybe have an option for HAVE_FIREWIRE
.include "../../wip/libraw1394/buildlink3.mk"
.include "../../wip/libavc1394/buildlink3.mk"

#.include "../../audio/libsndfile/buildlink3.mk"
#.include "../../wip/libuuid/buildlink3.mk"
#.include "../../audio/esound/buildlink3.mk"
#.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../graphics/tiff/buildlink3.mk"
#DEPENDS+=	toolame>=02:../../audio/toolame
#ifeq ($(HAVE_ALSA), y)
#.include "../../wip/alsa-lib/buildlink3.mk"

#  libmpeg3
# jpeg-mmx
#.include "../../audio/libogg/buildlink3.mk"
#.include "../../audio/libvorbis/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
