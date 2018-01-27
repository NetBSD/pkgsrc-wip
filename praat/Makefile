# $NetBSD$

DISTNAME=	praat-6.0.16
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=praat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	cherry@NetBSD.org
HOMEPAGE=	http://www.praat.org/
COMMENT=	Doing phonetics by computer
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake pkg-config

NO_CONFIGURE=	yes
MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin # ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/praat ${DESTDIR}${PREFIX}/bin/praat
#XXX:   ${INSTALL_MAN} ${WRKSRC}/praat.1    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/gtk2/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
