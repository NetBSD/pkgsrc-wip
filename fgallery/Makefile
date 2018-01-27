# $NetBSD$

PORTVERSION=	1.8.2
PKGBASE=	fgallery
DISTNAME=	${PKGBASE}-${PORTVERSION}
PKGREVISION=	4
CATEGORIES=	www

MASTER_SITES=	http://www.thregr.org/~wavexx/software/fgallery/releases/
EXTRACT_SUFX=	.zip

MAINTAINER=	ast@NetBSD.org
HOMEPAGE=	http://www.thregr.org/~wavexx/software/fgallery
COMMENT=	Minimilistic, static photo gallery generator
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes
USE_TOOLS+=	perl
REPLACE_PERL=	${PKGBASE}

DEPENDS+=	facedetect>=0.1:../../wip/facedetect
DEPENDS+=	ImageMagick>=6.9:../../graphics/ImageMagick
DEPENDS+=	jpegoptim>=1.4:../../graphics/jpegoptim
DEPENDS+=	pngcrush>=1.7:../../graphics/pngcrush
DEPENDS+=	lcms2>=2.7:../../graphics/lcms2
DEPENDS+=	p7zip>=9.38:../../archivers/p7zip
DEPENDS+=	p5-Image-ExifTool>=10.0:../../graphics/p5-Image-ExifTool

FG_SHAREDIR=	share/${PKGBASE}
FG_VIEWDIR=	share/${PKGBASE}/view

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-patch
SUBST_MESSAGE.fix-paths=	Fixing ${FG_VIEWDIR} path.
SUBST_FILES.fix-paths=		fgallery
SUBST_SED.fix-paths=		-e "s,%%FG_VIEWDIR%%,${PREFIX}/${FG_VIEWDIR},g"

SUBST_CLASSES+=		fix-vers
SUBST_STAGE.fix-vers=	post-patch
SUBST_MESSAGE.fix-vers=	Setting version to ${PKGVERSION:C/^.*-//}.
SUBST_FILES.fix-vers=	fgallery
SUBST_SED.fix-vers=	-e "s,\"${PORTVERSION}\",\"${PKGVERSION:C/^.*-//}\","

FG_DOCS=	COPYING.txt NEWS.html NEWS.rst README.html README.rst
FG_SRCDIR=	${WRKDIR}/${DISTNAME}
FG_VIEWFILES=	back.png \
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
                mootools-core-1.4.js \
                mootools-idle.js \
                mootools-mooswipe.js \
                mootools-more-1.4.js \
                noise.png \
                throbber.gif

OV_FILES=	overview.css \
                overview.html \
                overview.js \
                overview.png \
                noscript.css

INSTALLATION_DIRS=	bin ${FG_SHAREDIR} ${FG_VIEWDIR}

pre-patch:
.for file in ${OV_FILES}
	${CP} ${FILESDIR}/${file} ${WRKSRC}/view
.endfor

do-install:
	${INSTALL_SCRIPT} ${FG_SRCDIR}/${PKGBASE} ${DESTDIR}${PREFIX}/bin/${PKGBASE}

post-install:
.for file in ${FG_DOCS}
	${INSTALL_DATA} ${FG_SRCDIR}/${file} ${DESTDIR}${PREFIX}/${FG_SHAREDIR}
.endfor
.for file in ${FG_VIEWFILES} ${OV_FILES}
	${INSTALL_DATA} ${FG_SRCDIR}/view/${file} ${DESTDIR}${PREFIX}/${FG_VIEWDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
