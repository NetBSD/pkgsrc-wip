# $NetBSD: Makefile,v 1.6 2012/10/03 15:10:00 asau Exp $

DISTNAME=		muscleframework-1.1.5
PKGNAME=		muscle-pkcs11-1.1.5
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://alioth.debian.org/download.php/463/

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://www.linuxnet.com/
COMMENT=	MUSCLE SmartCard framework PKCS \#11 library


WRKSRC=			${WRKDIR}/${DISTNAME}/libmusclepkcs11
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake

CPPFLAGS+=		-I${LOCALBASE}/include/PCSC

EGDIR=			${PREFIX}/share/examples/muscle-pkcs11

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/pkcs11rc.example ${EGDIR}

.include "../../wip/libmusclecard/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
