# $NetBSD: Makefile,v 1.1.1.1 2005/07/28 19:38:07 udontknow Exp $

DISTNAME=		muscleframework-1.1.5
PKGNAME=		muscle-cflexplugin-1.1.5
CATEGORIES=		security
MASTER_SITES=		http://alioth.debian.org/download.php/463/

MAINTAINER=     	evaldo@gardenali.biz
HOMEPAGE=       	http://www.linuxnet.com/
COMMENT=		CryptoFlex plugin for the MUSCLE framework

WRKSRC=			${WRKDIR}/${DISTNAME}/CFlexPlugin
GNU_CONFIGURE=		YES
USE_PKGINSTALL=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		automake gmake

CONTSRCDIR=	${WRKSRC}/src/slbCryptoflex.bundle/Contents/
CONTDIR=	${PREFIX}/lib/pcsc-lite/drivers/slbCryptoflex.bundle/Contents
CONTLIBDIR=	${CONTDIR}/${OPSYS}

do-install:
	${INSTALL_DATA_DIR} ${CONTDIR}
	${INSTALL_DATA} ${CONTSRCDIR}/Info.plist ${CONTDIR}
	${INSTALL_DATA} ${CONTSRCDIR}/PkgInfo ${CONTDIR}
	${INSTALL_DATA_DIR} ${CONTDIR}/Resources
	${INSTALL_DATA_DIR} ${CONTDIR}/Resources/English.lproj
	${INSTALL_DATA} \
		${CONTSRCDIR}/Resources/English.lproj/InfoPlist.strings \
		${CONTDIR}/Resources/English.lproj/InfoPlist.strings
	${INSTALL_LIB_DIR} ${CONTLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/src/.libs/libcryptoflex.so ${CONTLIBDIR}

.include "../../wip/libmusclecard/buildlink3.mk"
.include "../../wip/pcsc-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
