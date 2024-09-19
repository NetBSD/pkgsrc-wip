# $NetBSD: Makefile,v 1.9 2012/10/03 18:07:14 asau Exp $

DISTNAME=	nxclient-${NX_VER}.i386
PKGNAME=	nx-client-bin-${NX_VER}
CATEGORIES=	net
MASTER_SITES=	http://web04.nomachine.com/download/3.4.0/Linux/

MAINTAINER=	tonnerre@NetBSD.org
COMMENT=	NX linux client binary

NX_VER=		3.4.0-5

WRKSRC?=	${WRKDIR}/NX
BUILD_DIRS=	# empty
NO_CONFIGURE=	yes
USE_LANGUAGES=	# empty

NX=		nx
NX_SCRIPT=	${NX}.sh
NX_LIB=		${PREFIX}/lib/${NX}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat png x11

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/${NX_SCRIPT}
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	SH
SUBST_VARS.paths+=	NX
SUBST_STAGE.paths=	post-patch

INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${FILESDIR}/${NX_SCRIPT} ${WRKDIR}/${NX_SCRIPT}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${NX_LIB}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${NX_LIB}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${NX_LIB}/share
.for file in nxclient nxesd nxkill nxprint nxservice nxssh
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${DESTDIR}${NX_LIB}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/${NX_SCRIPT} ${DESTDIR}${PREFIX}/bin/nx
.for file in libXcomp.so libXcomp.so.3 libXcomp.so.3.4.0 libXcompsh.so libXcompsh.so.3 libXcompsh.so.3.4.0 libcrypto.so libcrypto.so.0.9.8 libjpeg.so libjpeg.so.62 libjpeg.so.62.0.0 libpng12.so libpng12.so.0 libpng12.so.0.1.2.8 libz.so libz.so.1 libz.so.1.2.3
	${INSTALL_LIB} ${WRKSRC}/lib/${file} ${DESTDIR}${NX_LIB}/lib
.endfor
.for file in keyboards rgb
	${INSTALL_DATA} ${WRKSRC}/share/${file} ${DESTDIR}${NX_LIB}/share
.endfor
.for dir in cups documents/client icons/16x16 icons/22x22 icons/32x32 icons/48x48 images keys
	${INSTALL_DATA_DIR} ${DESTDIR}${NX_LIB}/share/${dir}
	${INSTALL_DATA} ${WRKSRC}/share/${dir}/* ${DESTDIR}${NX_LIB}/share/${dir}
.endfor

.include "../../mk/bsd.pkg.mk"
