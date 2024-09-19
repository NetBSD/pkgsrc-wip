# $NetBSD$

GITHUB_PROJECT=	goldendict
DISTNAME=	goldendict-1.5.0rc2
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	-https://github.com/${GITHUB_PROJECT}/${DIST_SUBDIR}/archive/1.5.0-RC2.tar.gz
DIST_SUBDIR=	${GITHUB_PROJECT}
WRKSRC=		${WRKDIR}/goldendict-1.5.0-RC2

QMAKE=	${QTDIR}/bin/qmake

MAINTAINER=	jake.slazenger@yandex.com
HOMEPAGE=	https://github.com/goldendict/goldendict/
COMMENT=	Dictionary lookup program
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

do-configure:
	cd ${WRKSRC} && \
		${QMAKE} -o Makefile goldendict.pro  \
		INCLUDEPATH+="${PREFIX}/${BUILDLINK_INCDIRS.ffmpeg3}" \
		QMAKE_LIBDIR+="${PREFIX}/${BUILDLINK_LIBDIRS.ffmpeg3}" \
		PREFIX=${DESTDIR}/${PREFIX} \
		#CONFIG+=debug   # Debug mode for GoldenDict

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../multimedia/phonon/buildlink3.mk"
.include "../../textproc/eb/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
