# $NetBSD: Makefile,v 1.7 2010/12/26 05:01:23 davesainty Exp $
#

DISTNAME=		molmol-2k.2.0-src
PKGNAME=		molmol-2.2.0
PKGREVISION=		2
CATEGORIES=		biology
MASTER_SITES=		ftp://freedom7.swmed.edu/pub/software/MOLMOL/unix-gzip/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.mol.biol.ethz.ch/wuthrich/software/molmol/
COMMENT=		Graphics Program for manipulating 3D biological macromolecules

USE_LIBTOOLS=		yes

WRKSRC=			${WRKDIR}

post-configure:
	${CP} ${WRKSRC}/makedef.lnx ${WRKSRC}/makedef

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/main/molmol ${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
