# $NetBSD: Makefile,v 1.8 2010/01/18 09:38:18 thomasklausner Exp $
#

#DISTNAME=		cinelerra-1.2.0-src
DISTNAME=		hvirtual_1.2.0-2cvs20040814
PKGNAME=		cinelerra-1.2.0-2cvs20040814
PKGREVISION=		1
CATEGORIES=		multimedia
# unofficial source is here
MASTER_SITES=		http://www.kiberpipa.org/~minmax/cinelerra/builds/sid/
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heroines/}
#EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
#HOMEPAGE=		http://heroines.sourceforge.net/
HOMEPAGE=		http://cvs.cinelerra.org/
COMMENT=		Non-linear video and audio editor and compositor (unofficial)

#DEPENDS+=	toolame>=02:../../audio/toolame

#WRKSRC=			${WRKDIR}/cinelerra-1.2.0/cinelerra
#WRKSRC=			${WRKDIR}/cinelerra-1.2.0
WRKSRC=			${WRKDIR}/hvirtual
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

# maybe have an option for HAVE_ALSA
.include "../../wip/alsa-lib/buildlink3.mk"
.include "../../audio/esound/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
# what can be done about ACCEPTABLE_LICENSES=fee-based-commercial-use ?
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
#.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"

.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/libdv/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"

# maybe have an option for HAVE_FIREWIRE
.include "../../wip/libraw1394/buildlink3.mk"
.include "../../wip/libavc1394/buildlink3.mk"

#  libmpeg3
# jpeg-mmx
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../wip/libuuid/buildlink3.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
