# $NetBSD: Makefile,v 1.4 2012/11/25 23:32:23 othyro Exp $
#

DISTNAME=		gnu-crypto-2.0.1-bin
PKGNAME=		java-gnucrypto-2.0.1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/GnuPG/gnu-crypto/
EXTRACT_SUFX=		.zip
LICENSE=		gnu-gpl-v2

MAINTAINER=		pkgsrc-users@NetBSD.org
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
