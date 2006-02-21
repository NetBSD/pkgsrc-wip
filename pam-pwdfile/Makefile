# $NetBSD: Makefile,v 1.1.1.1 2006/02/21 09:25:27 bartoszkuzma Exp $
#

DISTNAME=		pam_pwdfile-0.99
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		security
MASTER_SITES=		http://cpbotha.net/files/pam_pwdfile/

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://cpbotha.net/pam_pwdfile.html
COMMENT=		PAM module for authenticating with text password files

pre-build:
	${CP} files/_pam_macros.h ${WRKSRC}

do-build:
	cd ${WRKSRC} && \
	${CC} -fPIC -Wall -c pam_pwdfile.c && \
	${CC} -fPIC -Wall -c bigcrypt.c && \
	${CC} -fPIC -Wall -DHIGHFIRST -D'MD5Name(x)=Good##x' \
		-c md5.c -o md5_good.o && \
	${CC} -fPIC -Wall -D'MD5Name(x)=Broken##x' \
		-c md5.c -o md5_broken.o && \
	${CC} -fPIC -Wall -D'MD5Name(x)=Good##x' \
		-c md5_crypt.c -o md5_crypt_good.o && \
	${CC} -fPIC -Wall -D'MD5Name(x)=Broken##x' \
		-c md5_crypt.c -o md5_crypt_broken.o && \
	${LD} -x --shared -o pam_pwdfile.so \
		pam_pwdfile.o md5_good.o md5_crypt_good.o md5_broken.o \
		md5_crypt_broken.o bigcrypt.o -lpam -lcrypt

do-install:
	${INSTALL_DATA} ${WRKSRC}/pam_pwdfile.so ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pam-pwdfile
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pam-pwdfile
	${INSTALL_DATA} ${WRKSRC}/changelog ${PREFIX}/share/doc/pam-pwdfile

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
