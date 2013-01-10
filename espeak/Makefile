# $NetBSD: Makefile,v 1.1 2013/01/10 01:41:39 makoto Exp $
#

DISTNAME=	espeak-${ESPEAK_VERSION}${ESPEAK_MINOR}-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=espeak/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://espeak.sourceforge.net/
COMMENT=	Speech synthesizer
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/src

ESPEAK_VERSION=	1.46
ESPEAK_MINOR=	.02
INSTALLATION_DIRS=	bin include lib share

SUBST_CLASSES+=		datadir
SUBST_MESSAGE.datadir=	Replacing hardcoded DATADIR path
SUBST_STAGE.datadir=	post-patch
SUBST_VARS.datadir=	PREFIX
SUBST_FILES.datadir=	Makefile speech.h
SUBST_SED.datadir=	-e 's|/usr/share|${PREFIX}/share|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/espeak ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libespeak.so.1.${ESPEAK_VERSION} ${DESTDIR}${PREFIX}/lib
	${LN} -sf libespeak.so.1.${ESPEAK_VERSION} \
		${DESTDIR}${PREFIX}/lib/libespeak.so.1
	${LN} -sf libespeak.so.1.${ESPEAK_VERSION} \
		${DESTDIR}${PREFIX}/lib/libespeak.so
	${INSTALL_LIB} ${WRKSRC}/libespeak.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/speak_lib.h ${DESTDIR}${PREFIX}/include
	${CP} -r ${WRKDIR}/espeak-${ESPEAK_VERSION}${ESPEAK_MINOR}-source/espeak-data \
		${DESTDIR}${PREFIX}/share

# Using v18 (v19 will get undefined reference to `Pa_StreamActive')
.include "../../audio/portaudio/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
