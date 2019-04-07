# $NetBSD$

PORTVERSION=	2.4
PKGBASE=	efgallery
DISTNAME=	${PKGBASE}-${PORTVERSION}
PKGREVISION=	2
CATEGORIES=	www

MASTER_SITES=	${MASTER_SITE_GITHUB:=0-ast-0/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_TAG=	${PORTVERSION}

MAINTAINER=	ast@NetBSD.org
HOMEPAGE=	https://github.com/0-ast-0/efgallery
COMMENT=	Minimilistic photo gallery generator in Perl
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

EFG_SHAREDIR=	share/${PKGBASE}
EFG_VIEWDIR=	share/${PKGBASE}/view

SUBST_CLASSES+=		fix-vers
SUBST_STAGE.fix-vers=	pre-configure
SUBST_FILES.fix-vers=	efgallery
SUBST_MESSAGE.fix-vers=	Setting version in ${SUBST_FILES.fix-vers} to ${PKGVERSION:C/^.*-//}.
SUBST_SED.fix-vers=	-e "/^our/ s,\"${PORTVERSION}\",\"${PKGVERSION:C/^.*-//}\","

EFG_DOCS=	COPYING.txt README.md
EFG_SRCDIR=	${WRKDIR}/${DISTNAME}
EFG_VIEWFILES=	back.png \
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
		throbber.gif \
		overview.css \
		overview.html \
		overview.js \
		overview.png

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EFG_SHAREDIR} ${EFG_VIEWDIR}

do-install:
	${INSTALL_SCRIPT} ${EFG_SRCDIR}/${PKGBASE} \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_MAN} ${WRKSRC}/efgallery.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

post-install:
.for file in ${EFG_DOCS}
	${INSTALL_DATA} ${EFG_SRCDIR}/${file} \
		${DESTDIR}${PREFIX}/${EFG_SHAREDIR}
.endfor
.for file in ${EFG_VIEWFILES}
	${INSTALL_DATA} ${EFG_SRCDIR}/view/${file} \
		${DESTDIR}${PREFIX}/${EFG_VIEWDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
