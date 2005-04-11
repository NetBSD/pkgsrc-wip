# $NetBSD: Makefile,v 1.2 2005/04/11 21:10:45 tvierling Exp $
#

DISTNAME=		clustalx1.83.sun
PKGNAME=		clustalx-1.83
WRKSRC=                 ${WRKDIR}/clustalx1.83.sun
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp-igbmc.u-strasbg.fr/pub/ClustalX/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www-igbmc.u-strasbg.fr/BioInfo/ClustalX/Top.html
COMMENT=		X-Windows interface for ClustalW

MESSAGE_SUBST+=         PREFIX=${PREFIX}
MAKEFILE=		makefile
USE_X11=		yes


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
.include "../../mk/bsd.pkg.mk"
