# $NetBSD: Makefile,v 1.5 2012/10/03 14:53:49 asau Exp $

DISTNAME=		muscleframework-1.1.5
PKGNAME=		muscle-mcardplugin-1.1.5
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://alioth.debian.org/download.php/463/

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://www.linuxnet.com/
COMMENT=	MuscleCard applet plugin for the MUSCLE framework

WRKSRC=			${WRKDIR}/${DISTNAME}/MCardPlugin
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake

CPPFLAGS+=		-I${LOCALBASE}/include/PCSC

CONFIGURE_ARGS+=	--enable-callback

CONTSRCDIR=	${WRKSRC}/src/mscMuscleCard.bundle/Contents/
CONTDIR=	${PREFIX}/lib/pcsc-lite/drivers/mscMuscleCard.bundle/Contents
CONTLIBDIR=	${CONTDIR}/${OPSYS}

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${CONTDIR}
	${INSTALL_DATA} ${CONTSRCDIR}/Info.plist ${DESTDIR}${CONTDIR}
	${INSTALL_DATA} ${CONTSRCDIR}/PkgInfo ${DESTDIR}${CONTDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${CONTDIR}/Resources
	${INSTALL_DATA_DIR} ${DESTDIR}${CONTDIR}/Resources/English.lproj
	${INSTALL_DATA} \
		${CONTSRCDIR}/Resources/English.lproj/InfoPlist.strings \
		${DESTDIR}${CONTDIR}/Resources/English.lproj/InfoPlist.strings
	${INSTALL_LIB_DIR} ${DESTDIR}${CONTLIBDIR}
	libtool --mode=install ${INSTALL_LIB} ${WRKSRC}/src/libmusclecardApplet.la ${DESTDIR}${CONTLIBDIR}

.include "../../wip/libmusclecard/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
