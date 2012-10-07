# $NetBSD: Makefile,v 1.9 2012/10/07 18:57:22 asau Exp $
#

DISTNAME=		wise2.2.0
PKGNAME=		wise-2.2.0
PKGREVISION=		1
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/wise2/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.ebi.ac.uk/Wise2/
COMMENT=		Tool for Comparing bio polymers like DNA and Protein sequences

BUILD_DIRS=		src
MAKE_FILE=		makefile
MESSAGE_SUBST+=		PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/wise2/wisecfg
	cd ${WRKSRC}/wisecfg && ${INSTALL_DATA} * ${DESTDIR}${DESTDIR}${PREFIX}/share/wise2/wisecfg/
	cd ${WRKSRC}/src/bin && ${INSTALL_PROGRAM} * ${DESTDIR}${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
