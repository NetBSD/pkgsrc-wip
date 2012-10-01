# $NetBSD: Makefile,v 1.3 2012/10/01 20:34:09 asau Exp $
#

DISTNAME=		gnu-crypto-2.0.1-bin
PKGNAME=		java-gnucrypto-2.0.1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/GnuPG/gnu-crypto/
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://ftp.gnupg.org/GnuPG/gnu-crypto/
COMMENT=		Free cryptographic implementation for Java

do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/lib/gnu-crypto.jar \
		${DESTDIR}${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/lib/javax-crypto.jar \
		${DESTDIR}${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/lib/javax-security.jar \
		${DESTDIR}${PREFIX}/share/classpath/

.include "../../mk/bsd.pkg.mk"
