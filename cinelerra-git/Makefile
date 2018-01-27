# $NetBSD: Makefile,v 1.7 2014/08/11 23:10:13 thomasklausner Exp $

DISTNAME=	cinelerra-cv-2.1
CATEGORIES=	multimedia

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://cinelerra.org/
COMMENT=	Non-linear video and audio editor and compositor
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	master
GIT_REPO.master=	http://cinelerra.org/git-repo/cinelerra
GIT_DEEP_CLONE.master=	yes # server offers repository over dumb protocol
.include "../../wip/mk/git-package.mk"

WRKSRC=			${WRKDIR}/cinelerra
GNU_CONFIGURE=		yes
USE_TOOLS+=		automake gmake msgmerge pkg-config xgettext
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
REPLACE_PERL=		admin/nasm

CONFIGURE_ARGS+=	--with-external-ffmpeg

# These scripts don't pass the portability test but seem to be unused
# anyway.
CHECK_PORTABILITY_SKIP+= \
	libmpeg3/configure \
	quicktime/configure

post-patch:
	${RUN} cd ${WRKSRC} && \
		./autogen.sh

# We need 'xxd' in build time, which is in the vim-share package.
BUILD_DEPENDS+=	vim-share-[0-9]*:../../editors/vim-share

# cinelerra has some assembler source files.
BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/faac/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../multimedia/libdv/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
