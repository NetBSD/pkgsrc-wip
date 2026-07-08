# $NetBSD$
#

DISTNAME=		libpam-pwdfile-2.0
PKGNAME=		${DISTNAME:S/lib//}
CATEGORIES=		security
MASTER_SITES=		https://git.tiwe.de/libpam-pwdfile.git/snapshot/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://git.tiwe.de/libpam-pwdfile.git
COMMENT=		PAM module for authenticating with text password files
LICENSE=		modified-bsd

USE_LIBTOOL=		yes

.include "../../mk/bsd.prefs.mk"

LDLIBS=			-lpam
.if ${OPSYS} != "Darwin"
LDLIBS+=		-lcrypt
.endif

INSTALLATION_DIRS+=	lib/security share/doc/pam-pwdfile

do-build:
	cd ${WRKSRC} && \
	${SHLIBTOOL} --mode=compile ${CC} -c pam_pwdfile.c -o pam_pwdfile.o && \
	${SHLIBTOOL} --mode=link ${CC} -avoid-version -module ${LDLIBS} \
		-o pam_pwdfile.la -rpath ${PREFIX}/lib/security \
		pam_pwdfile.lo

do-install:
	${SHLIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		-c ${WRKSRC}/pam_pwdfile.la ${DESTDIR}${PREFIX}/lib/security
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/pam-pwdfile

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
