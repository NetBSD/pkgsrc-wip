# $NetBSD: Makefile,v 1.4 2005/06/12 23:51:16 kristerw Exp $
#

DISTNAME=		clustalx1.83.sun
PKGNAME=		clustalx-1.83
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp-igbmc.u-strasbg.fr/pub/ClustalX/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www-igbmc.u-strasbg.fr/BioInfo/ClustalX/Top.html
COMMENT=		X-Windows interface for ClustalW

WRKSRC=                 ${WRKDIR}/clustalx1.83.sun
MESSAGE_SUBST+=         PREFIX=${PREFIX}
MAKEFILE=		makefile

do-install:
.for PROGRAM in clustalx
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
.endfor
.for PRG in coldna.par colprint.par colprot.par clustalx_help
	${INSTALL_DATA} ${WRKSRC}/${PRG} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/clustalx
.for DOC in README_X clustalx.html
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/doc/clustalx
.endfor

.include "../../wip/ncbi-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
