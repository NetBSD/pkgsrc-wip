# $NetBSD: Makefile,v 1.1.1.1 2004/03/09 00:31:31 poppnk Exp $
#

DISTNAME=		gnu-crypto-2.0.1-bin
PKGNAME=		java-gnucrypto-2.0.1
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gnupg.org/GnuPG/gnu-crypto/
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://ftp.gnupg.org/GnuPG/gnu-crypto/
COMMENT=		Free cryptographic implementation for Java

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/lib/gnu-crypto.jar \
		${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/lib/javax-crypto.jar \
		${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/lib/javax-security.jar \
		${PREFIX}/share/classpath/

.include "../../mk/bsd.pkg.mk"
