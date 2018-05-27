# $NetBSD: Makefile,v 1.2 2015/08/25 13:41:23 leot1990 Exp $
#

DISTNAME=	espeak-1.48.04-source
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

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DATADIR=${PREFIX}/share/espeak-data

SUBST_CLASSES+=		datadir
SUBST_MESSAGE.datadir=	Replacing hardcoded DATADIR path
SUBST_STAGE.datadir=	post-patch
SUBST_FILES.datadir=	speech.h
SUBST_SED.datadir=	-e 's|/usr/share|${PREFIX}/share|'

post-install:
	cd ${WRKSRC} && ${FIND} ${DESTDIR}${PREFIX}/share -type f \
	    -exec ${CHMOD} ${SHAREMODE} {} \;

# Using v18 (v19 will get undefined reference to `Pa_StreamActive')
.include "../../audio/portaudio/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
