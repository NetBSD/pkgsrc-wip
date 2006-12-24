# $NetBSD: Makefile,v 1.2 2006/12/24 16:16:50 rumko Exp $

DISTNAME=	nxclient-${NX_VER}.i386
PKGNAME=	nx-client-bin-${NX_VER}
#PKGREVISION=
CATEGORIES=	net
MASTER_SITES=	http://web04.nomachine.com/download/2.1.0/Linux-NoXft/

MAINTAINER=	rumcic@gmail.com
COMMENT=	NX linux client binary

NX_VER=		2.1.0-11

WRKSRC?=	${WRKDIR}/NX
NO_CONFIGURE=	yes
USE_LANGUAGES=	# empty

NX=		nx
NX_SCRIPT=	${NX}.sh
NX_LIB=		${PREFIX}/lib/${NX}

SUBST_CLASSES+=         paths
SUBST_FILES.paths=      ${WRKDIR}/${NX_SCRIPT}
SUBST_SED.paths+=       -e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=       -e 's,@SH@,${SH},g'
SUBST_SED.paths+=       -e 's,@NX@,${NX},g'
SUBST_STAGE.paths=      post-patch



.include "../../emulators/suse_linux/Makefile.application"
DEPENDS+=	suse_libpng>=9.1:../../emulators/${SUSE_DIR_PREFIX}_libpng

post-extract:
	${CP} ${FILESDIR}/${NX_SCRIPT} ${WRKDIR}/${NX_SCRIPT}

do-build:

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
.for dir in
	${INSTALL_DATA_DIR} ${WRKSRC}/share/${dir} ${NX_LIB}/share
.endfor

.include "../../mk/bsd.pkg.mk"
