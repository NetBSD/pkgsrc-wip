# $NetBSD: Makefile,v 1.4 2012/10/04 19:28:16 asau Exp $

DISTNAME=	pam_pop3-1.0
PKGNAME=	pam-pop3-1.0
CATEGORIES=	security
MASTER_SITES=	http://shum.huji.ac.il/~schapiro/linux/pam_pop3/

MAINTAINER=	david@netbsd-fr.org
COMMENT=	This module authenticates a user against a POP3 server

WRKSRC=		${WRKDIR}/pam_pop3

INSTALLATION_DIRS=	lib

do-build:
	${CC} ${CFLAGS} -fpic -DPIC -Wall -c ${WRKSRC}/pam_pop3.c \
		-o ${WRKSRC}/pam_pop3.o
	${LD} -x --shared -o ${WRKSRC}/pam_pop3.so ${WRKSRC}/pam_pop3.o \
		-L ${PREFIX}/lib -lpam -lcrypt

do-install:
	${INSTALL_DATA} ${WRKSRC}/pam_pop3.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/pam-pop3
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pam-pop3

.include "../../security/PAM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
