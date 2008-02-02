# $NetBSD: Makefile,v 1.7 2008/02/02 15:00:38 rillig Exp $
#

DISTNAME=		wise2.2.0
PKGNAME=		wise-2.2.0
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/wise2/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.ebi.ac.uk/Wise2/
COMMENT=		Tool for Comparing bio polymers like DNA and Protein sequences

BUILD_DIRS=		src
MAKE_FILE=		makefile
MESSAGE_SUBST+=		PREFIX=${PREFIX}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/wise2/wisecfg
	cd ${WRKSRC}/wisecfg && ${INSTALL_DATA} * ${DESTDIR}${PREFIX}/share/wise2/wisecfg/
	cd ${WRKSRC}/src/bin && ${INSTALL_PROGRAM} * ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
