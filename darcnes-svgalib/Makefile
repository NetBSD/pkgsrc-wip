# $NetBSD: Makefile,v 1.2 2003/08/04 19:17:45 bencollver Exp $

PKGNAME=	darcnes-svgalib-20010401

MAINTAINER=	collver1@comcast.net
COMMENT=	Multi-system emulator, svgalib display

MAKE_ENV+=	TARGET=Linux_svgalib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdarcnes ${PREFIX}/bin/darcnes-svgalib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/darcnes-svgalib
	${INSTALL_MAN} ${WRKSRC}/readme ${PREFIX}/share/doc/darcnes-svgalib

.include "../../emulators/darcnes/Makefile.common"
.include "../../wip/svgalib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
