# $NetBSD: Makefile,v 1.5 2012/09/24 16:56:31 asau Exp $
#

DISTNAME=		aespipe-v2.3b
PKGNAME=		aespipe-2.3b
CATEGORIES=		security
MASTER_SITES=		http://loop-aes.sourceforge.net/aespipe/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://loop-aes.sourceforge.net/aespipe/
COMMENT=		AES encryption pipe from the loop-aes project


DEPENDS+=		gnupg>=1.2.0:../../security/gnupg

GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM+=	Linux-*-i[3-6]86

.if ${MACHINE_ARCH} == "x86_64"
BUILD_TARGET=		amd64
.elif ${MACHINE_ARCH} == "i386"
BUILD_TARGET=		x86
.else
BUILD_TARGET=		${EMPTY}
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bz2aespipe ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/aespipe
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/aespipe

.include "../../mk/bsd.pkg.mk"
