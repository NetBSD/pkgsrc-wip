# $NetBSD: Makefile,v 1.7 2007/07/30 15:49:10 jlamwww Exp $

DISTNAME=	nxclient-${NX_VER}.i386
PKGNAME=	nx-client-bin-${NX_VER}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://web04.nomachine.com/download/2.1.0/Linux-NoXft/

MAINTAINER=	rumcic@gmail.com
COMMENT=	NX linux client binary

NX_VER=		2.1.0-11

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
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@SH@,${SH},g'
SUBST_SED.paths+=	-e 's,@NX@,${NX},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/${NX_SCRIPT} ${WRKDIR}/${NX_SCRIPT}

do-install:
	${INSTALL_DATA_DIR} ${NX_LIB}/bin
	${INSTALL_DATA_DIR} ${NX_LIB}/lib
	${INSTALL_DATA_DIR} ${NX_LIB}/share
.for file in nxclient nxesd nxkill nxprint nxservice nxssh
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${NX_LIB}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/${NX_SCRIPT} ${PREFIX}/bin/nx
.for file in libXcomp.so libXcomp.so.2 libXcomp.so.2.1.0 libXcompsh.so libXcompsh.so.2 libXcompsh.so.2.1.0 libcrypto.so libcrypto.so.0.9.8 libjpeg.so libjpeg.so.62 libjpeg.so.62.0.0 libpng12.so libpng12.so.0 libpng12.so.0.1.2.8 libz.so libz.so.1 libz.so.1.2.3
	${INSTALL_LIB} ${WRKSRC}/lib/${file} ${NX_LIB}/lib
.endfor
.for file in keyboards rgb
	${INSTALL_DATA} ${WRKSRC}/share/${file} ${NX_LIB}/share
.endfor
.for dir in cups documents/client icons images keys
	${INSTALL_DATA_DIR} ${NX_LIB}/share/${dir}
	${INSTALL_DATA} ${WRKSRC}/share/${dir}/* ${NX_LIB}/share/${dir}
.endfor

.include "../../mk/bsd.pkg.mk"
