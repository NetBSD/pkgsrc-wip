# $NetBSD$

DISTNAME=	chntpw-source-140201
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	security
MASTER_SITES=	https://pogostick.net/~pnh/ntpasswd/
EXTRACT_SUFX=	.zip

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://pogostick.net/~pnh/ntpasswd/
COMMENT=	Offline registry tools and password resetter
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAKE_FLAGS+=	CFLAGS="-DUSEOPENSSL -g -I. -Wall"
MAKE_FLAGS+=	LIBS=

BUILD_TARGET=	chntpw cpnt reged sampasswd samusrgrp

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/chntpw

BINFILES=	chntpw cpnt reged sampasswd samusrgrp
DOCFILES=	COPYING.txt GPL.txt HISTORY.txt INSTALL.txt LGPL.txt MANUAL.txt
DOCFILES+=	README.txt WinReg.txt regedit.txt syskey.txt

do-install:
.for file in ${BINFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/bin
.endfor
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/share/doc/chntpw
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
