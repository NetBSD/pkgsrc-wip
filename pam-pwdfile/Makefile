# $NetBSD: Makefile,v 1.7 2012/10/04 19:44:06 asau Exp $
#

DISTNAME=		pam_pwdfile-0.99
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://cpbotha.net/files/pam_pwdfile/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://cpbotha.net/pam_pwdfile.html
COMMENT=		PAM module for authenticating with text password files
LICENSE=		modified-bsd

USE_LIBTOOL=		yes

.include "../../mk/bsd.prefs.mk"

LDLIBS=			-lpam
.if ${OPSYS} != "Darwin"
LDLIBS+=		-lcrypt
.endif

pre-build:
	${CP} files/_pam_macros.h ${WRKSRC}

do-build:
	cd ${WRKSRC} && \
	${SHLIBTOOL} --mode=compile ${CC} -c pam_pwdfile.c -o pam_pwdfile.o && \
	${SHLIBTOOL} --mode=compile ${CC} -c bigcrypt.c -o bigcrypt.o && \
	${SHLIBTOOL} --mode=compile ${CC} -DHIGHFIRST -D'MD5Name(x)=Good##x' \
		-c md5.c -o md5_good.o && \
	${SHLIBTOOL} --mode=compile ${CC} -D'MD5Name(x)=Broken##x' \
		-c md5.c -o md5_broken.o && \
	${SHLIBTOOL} --mode=compile ${CC} -D'MD5Name(x)=Good##x' \
		-c md5_crypt.c -o md5_crypt_good.o && \
	${SHLIBTOOL} --mode=compile ${CC} -D'MD5Name(x)=Broken##x' \
		-c md5_crypt.c -o md5_crypt_broken.o && \
	${SHLIBTOOL} --mode=link ${CC} -avoid-version -module ${LDLIBS} \
		-o pam_pwdfile.la -rpath ${PREFIX}/lib/security \
		pam_pwdfile.lo md5_good.lo md5_crypt_good.lo md5_broken.lo \
		md5_crypt_broken.lo bigcrypt.lo

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/security
	${SHLIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		-c ${WRKSRC}/pam_pwdfile.la ${DESTDIR}${PREFIX}/lib/security
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/pam-pwdfile
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/pam-pwdfile
	${INSTALL_DATA} ${WRKSRC}/changelog \
		${DESTDIR}${PREFIX}/share/doc/pam-pwdfile

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
