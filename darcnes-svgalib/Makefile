# $NetBSD: Makefile,v 1.4 2012/09/28 20:47:10 asau Exp $

PKGNAME=	darcnes-svgalib-20010401

MAINTAINER=	collver1@comcast.net
COMMENT=	Multi-system emulator, svgalib display

MAKE_ENV+=	TARGET=Linux_svgalib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdarcnes ${DESTDIR}${PREFIX}/bin/darcnes-svgalib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/darcnes-svgalib
	${INSTALL_MAN} ${WRKSRC}/readme ${DESTDIR}${PREFIX}/share/doc/darcnes-svgalib

.include "../../emulators/darcnes/Makefile.common"
.include "../../wip/svgalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
