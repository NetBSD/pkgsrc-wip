# $NetBSD: Makefile,v 1.10 2009/11/21 20:31:26 mwdavies Exp $
#

DISTNAME=		k3b-1.68.0alpha3
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=k3b/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.k3b.org/
COMMENT=		DVD and CD authoring program

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/k3b-1.68.0

BUILD_DEPENDS+=		automoc4>=0.9.87:../../devel/automoc4
DEPENDS+=		cdrdao-[0-9]*:../../sysutils/cdrdao
DEPENDS+=		{cdrtools,cdrtools-ossdvd}-[0-9]*:../../sysutils/cdrtools

USE_CMAKE=		yes
USE_TOOLS+=		perl pkg-config
USE_LANGUAGES=		c c++

#CMAKE_ARGS+=		-DK3B_ENABLE_DVD_RIPPING=OFF
#CMAKE_ARGS+=            -DCMAKE_BUILD_TYPE=Debug

ONLY_FOR_PLATFORM=	FreeBSD-*-* Linux-*-* NetBSD-*-* DragonFly-*-*

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=   opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/kdemultimedia4/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../security/polkit-qt/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
