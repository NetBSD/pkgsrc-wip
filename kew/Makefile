# $NetBSD$

DISTNAME=	kew-2.8.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=ravachol/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/ravachol/kew/
COMMENT=	Terminal music player with album art
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config gmake

MAKE_FLAGS+=	MAN_DIR=${PREFIX}/${PKGMANDIR}

.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libatomic/buildlink3.mk"
.include "../../graphics/freeimage/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../wip/chafa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
