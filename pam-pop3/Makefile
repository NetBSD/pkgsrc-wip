# $NetBSD: Makefile,v 1.2 2004/04/25 18:24:15 blef Exp $

DISTNAME=	pam_pop3-1.0
PKGNAME=	pam-pop3-1.0
CATEGORIES=	security
MASTER_SITES=	http://shum.huji.ac.il/~schapiro/linux/pam_pop3/

MAINTAINER=	david@netbsd-fr.org
COMMENT=	This module authenticates a user against a POP3 server

WRKSRC=		${WRKDIR}/pam_pop3
USE_BUILDLINK3=	YES

do-build:
	${CC} ${CFLAGS} -fpic -DPIC -Wall -c ${WRKSRC}/pam_pop3.c \
		-o ${WRKSRC}/pam_pop3.o
	${LD} -x --shared -o ${WRKSRC}/pam_pop3.so ${WRKSRC}/pam_pop3.o \
		-L ${PREFIX}/lib -lpam -lcrypt

do-install:
	${INSTALL_DATA} ${WRKSRC}/pam_pop3.so ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pam-pop3
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pam-pop3

.include "../../security/PAM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
