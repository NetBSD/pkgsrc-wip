# $NetBSD: Makefile,v 1.6 2014/10/09 14:06:27 thomasklausner Exp $
#

DISTNAME=	goattrk2
PKGNAME=	goattracker-2.73
CATEGORIES=	audio
MASTER_SITES=	http://cadaver.homeftp.net/tools/
EXTRACT_SUFX=	.zip

MAINTAINER=	rodo@zlug.org
HOMEPAGE=	http://cadaver.homeftp.net/tools/
COMMENT=	Crossplatform C64 Music Editor

CFLAGS=			-I{PREFIX}/include -D_GNU_SOURCE=1 -D_REENTRANT -D_THREAD_SAFE
WRKSRC=			${WRKDIR}/src
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKE_FILE=		makefile
INSTALLATION_DIRS=	bin share/examples/goattracker share/doc/goattracker

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/src/goattrk2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/src/sngspli2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/src/mod2sng ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/src/ins2snd2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/src/betaconv ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/goattracker
	${INSTALL_DATA} ${WRKDIR}/examples/*.sng ${DESTDIR}${PREFIX}/share/examples/goattracker
	${INSTALL_DATA} ${WRKDIR}/examples/*.ins ${DESTDIR}${PREFIX}/share/examples/goattracker
	${INSTALL_DATA} ${WRKDIR}/examples/*.prg ${DESTDIR}${PREFIX}/share/examples/goattracker
	${INSTALL_DATA} ${WRKDIR}/examples/*.txt ${DESTDIR}${PREFIX}/share/examples/goattracker
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/goattracker
	${INSTALL_DATA} ${WRKDIR}/*.txt ${DESTDIR}${PREFIX}/share/doc/goattracker

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
