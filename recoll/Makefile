# $NetBSD: Makefile,v 1.3 2012/10/07 14:53:43 asau Exp $

DISTNAME=	recoll-1.35.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lesbonscomptes.com/recoll/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	https://www.lesbonscomptes.com/recoll/
COMMENT=	Full text desktop search engine
LICENSE=	gnu-gpl-v2

DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
DEPENDS+=	pstotext-[0-9]*:../../converters/pstotext
DEPENDS+=	antiword-[0-9]*:../../textproc/antiword
DEPENDS+=	libwpd-[0-9]*:../../converters/libwpd
DEPENDS+=	untex-[0-9]*:../../textproc/untex
DEPENDS+=	tex-dvips-[0-9]*:../../print/tex-dvips
DEPENDS+=	unrar-[0-9]*:../../archivers/unrar
DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool
DEPENDS+=	djvulibre-tools-[0-9]*:../../graphics/djvulibre-tools
DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-rarfile-[0-9]*:../../archivers/py-rarfile
#DEPENDS+=	${PYPKGPREFIX}-chm-[0-9]*:../../wip/py-chm
# RTF Files: unrtf
# Midi karaoke files need Python and the Midi module
# Konqueror webarchive format with Python (uses the Tarfile module).

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run pkg-config unzip:run

#CONFIGURE_ARGS+=	--disable-python-module
CONFIGURE_ARGS+=	--with-aspell=${BUILDLINK_PREFIX.aspell}/bin/aspell
CONFIGURE_ARGS+=	--with-file-command=${BUILDLINK_PREFIX.file}/bin/file

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/chmlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
# not found by configure even when enabled
#.include "../../sysutils/fam/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
