# $NetBSD$

PKGBASE=        fgallery
DISTNAME=       ${PKGBASE}-1.8.2
PKGREVISION=    1
CATEGORIES=     www

MASTER_SITES=   http://www.thregr.org/~wavexx/software/fgallery/releases/
EXTRACT_SUFX=   .zip

MAINTAINER=     ast@NetBSD.org
HOMEPAGE=       http://www.thregr.org/~wavexx/software/fgallery
COMMENT=        Minimilistic, static photo gallery generator
LICENSE=        gnu-gpl-v2

NO_BUILD=       yes
USE_TOOLS+=     perl
REPLACE_PERL=   ${PKGBASE}

DEPENDS+=       facedetect>=1.0:../../wip/facedetect
DEPENDS+=       ImageMagick>=6.9:../../graphics/ImageMagick
DEPENDS+=       jpegoptim>=1.4:../../graphics/jpegoptim
DEPENDS+=       pngcrush>=1.7:../../graphics/pngcrush
DEPENDS+=       lcms2>=2.7:../../graphics/lcms2
DEPENDS+=       p7zip>=9.38:../../archivers/p7zip
DEPENDS+=       p5-Image-ExifTool>=10.0:../../graphics/p5-Image-ExifTool

SUBST_CLASSES+=          fix-paths
SUBST_STAGE.fix-paths=   post-patch
SUBST_MESSAGE.fix-paths= Fixing absolute paths.
SUBST_FILES.fix-paths=   fgallery
SUBST_SED.fix-paths=     -e "s,\"\$$RealBin/,\"${PREFIX}/share/fgallery/,g"

FG_DOCSDIR=     share/doc/${PKGBASE}
FG_DOCS=        COPYING.txt NEWS.html NEWS.rst README.html README.rst
FG_SHAREDIR=    share/${PKGBASE}/view
FG_SRCDIR=      ${WRKDIR}/${DISTNAME}
FG_VIEWDIR=     ${FG_SRCDIR}/view
FG_VIEWFILES=   back.png \
		cap-always.png \
		cap-never.png \
		cap-normal.png \
                cut-left.png \
                cut-mov.png \
                cut-right.png \
                cut-top.png \
                download.png \
                eye.png \
                index.css \
                index.html \
                index.js \
                left.png \
                mootools-core-1.4.js \
                mootools-idle.js \
                mootools-mooswipe.js \
                mootools-more-1.4.js \
                noise.png \
                right.png \
                throbber.gif

INSTALLATION_DIRS= bin ${FG_DOCSDIR} ${FG_SHAREDIR}

do-install:
	${INSTALL_SCRIPT} ${FG_SRCDIR}/${PKGBASE} ${DESTDIR}${PREFIX}/bin/${PKGBASE}

post-install:
.for file in ${FG_DOCS}
	${INSTALL_DATA} ${FG_SRCDIR}/${file} ${DESTDIR}${PREFIX}/${FG_DOCSDIR}
.endfor
.for file in ${FG_VIEWFILES}
	${INSTALL_DATA} ${FG_VIEWDIR}/${file} ${DESTDIR}${PREFIX}/${FG_SHAREDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
