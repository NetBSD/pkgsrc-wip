# $NetBSD$

DISTNAME=	openssh-8.0p1
PKGNAME=	ssh-copy-id-${DISTNAME:S/openssh-//:S/p1/.1/}
CATEGORIES=	security

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://www.openssh.com/
COMMENT=	Use locally available keys to authorise logins on a remote machine
LICENSE=	modified-bsd

PATCHDIR=	${.CURDIR}/../../security/openssh/patches
DISTINFO_FILE=	${.CURDIR}/../../security/openssh/distinfo

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

USE_LANGUAGES=	# none
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/ssh-copy-id	\
		${DESTDIR}${PREFIX}/bin/ssh-copy-id
	${INSTALL_MAN} ${WRKSRC}/contrib/ssh-copy-id.1 			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ssh-copy-id.1

.include "../../mk/bsd.pkg.mk"
