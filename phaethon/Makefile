# $NetBSD$

DISTNAME=	phaethon-${GITHUB_TAG}
PKGNAME=	phaethon-${GITHUB_TAG:S/v//}
CATEGORIES=	games devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=xoreos/}
GITHUB_TAG=	v0.0.5

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://xoreos.org/
COMMENT=	Resource explorer for BioWare Aurora engine games
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/phaethon ${DESTDIR}${PREFIX}/bin/phaethon

.include "../../archivers/xz/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
