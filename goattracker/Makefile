# $NetBSD: Makefile,v 1.1.1.1 2009/10/09 11:14:03 rodo6510 Exp $
#

DISTNAME=	goattrk2
PKGNAME=	goattracker-2.68
CATEGORIES=	audio
MASTER_SITES=	http://cadaver.homeftp.net/tools/
EXTRACT_SUFX=	.zip

MAINTAINER= 	rodo@zlug.org
HOMEPAGE=	http://cadaver.homeftp.net/tools/
COMMENT=	Crossplatform C64 Music Editor

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/src
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKE_FILE=		makefile.common
INSTALLATION_DIRS=	bin share/examples/goattracker share/doc/goattracker

do-install:

	${INSTALL_PROGRAM} ${WRKDIR}/linux/goattrk2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/linux/sngspli2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/linux/mod2sng ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/linux/ins2snd2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/linux/betaconv ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/goattracker
	${INSTALL_DATA} ${WRKDIR}/examples/*.sng ${DESTDIR}${PREFIX}/share/examples/goattracker
	${INSTALL_DATA} ${WRKDIR}/examples/*.ins ${DESTDIR}${PREFIX}/share/examples/goattracker
	${INSTALL_DATA} ${WRKDIR}/examples/*.prg ${DESTDIR}${PREFIX}/share/examples/goattracker
	${INSTALL_DATA} ${WRKDIR}/examples/*.txt ${DESTDIR}${PREFIX}/share/examples/goattracker
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/goattracker
	${INSTALL_DATA} ${WRKDIR}/*.txt ${DESTDIR}${PREFIX}/share/doc/goattracker

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
