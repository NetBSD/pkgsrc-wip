# $NetBSD: Makefile,v 1.1.1.1 2010/09/02 11:57:25 jihbed Exp $
#

VERSION=	1.0.2
DISTNAME=	nsc2ke
PKGNAME=	${DISTNAME}-${VERSION}
CATEGORIES=	math
MASTER_SITES=	http://pauillac.inria.fr/cdrom_a_graver/ftp/nsc2ke/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pauillac.inria.fr/cdrom_a_graver/www/nsc2ke/eng.htm
COMMENT=	Navier-Stokes solver

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

MAKE_FILE=	makefile
USE_TOOLS+=	gmake
USE_LANGUAGES=	fortran

EDGDIR=	${PREFIX}/share/examples/nsc2ke
FILES=	DATA MESH gnu.data

INSTALLATION_DIRS=	bin ${EDGDIR}


do-build:
	cd ${WRKSRC} && ${GMAKE}
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/bin/
.for f in ${FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${EDGDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
