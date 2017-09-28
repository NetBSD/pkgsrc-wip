# $NetBSD$

PORTREVISION=	0.1
PKGBASE=        facedetect
DISTNAME=       ${PKGBASE}-v${PORTREVISION}
PKGREVISION=    2
CATEGORIES=     graphics

MASTER_SITES=   ${MASTER_SITE_GITHUB:=wavexx/}
GITHUB_PROJECT= ${PKGBASE}
GITHUB_TAG=     v${PORTREVISION}
EXTRACT_OPTS_TAR= -s/facedetect-${PORTREVISION}/${DISTNAME}/p

MAINTAINER=     ast@NetBSD.org
HOMEPAGE=       http://www.thregr.org/~wavexx/software/facedetect/
COMMENT=        Simple face detector for batch processing
LICENSE=        gnu-gpl-v2

DEPENDS+=       opencv>=2.4:../../graphics/opencv2

SUBST_CLASSES+=          fix-paths
SUBST_STAGE.fix-paths=   post-extract
SUBST_MESSAGE.fix-paths= Fixing absolute paths.
SUBST_FILES.fix-paths=   facedetect
SUBST_SED.fix-paths=     -e "s,'/usr/share/opencv,'${PREFIX}/share/OpenCV,g"

INSTALLATION_DIRS= bin ${FD_DOCSDIR}

FD_DOCSDIR=     share/doc/facedetect
FD_DOCS=        README.rst COPYING.txt doc/biggest-best.jpg

WRKSRC=         ${WRKDIR}/${DISTNAME}

NO_BUILD=        yes
REPLACE_PYTHON=  facedetect

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin/${PKGBASE}

post-install:
.for file in ${FD_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/${FD_DOCSDIR}
.endfor

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
