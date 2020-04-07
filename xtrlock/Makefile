# $NetBSD: Makefile,v 1.3 2012/10/07 19:57:17 asau Exp $
#

DISTNAME=	xtrlock-2.13
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xtrlock/}
EXTRACT_SUFX=	.tar.xz
DISTFILES=	xtrlock_2.13.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple X11 screen lock tool
LICENSE=	gnu-gpl-v3

USE_IMAKE=	yes

WRKSRC=		${WRKDIR}/xtrlock-2.13
MAN_PAGE=	${WRKSRC}/xtrlock.man

do-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} ${MAKE_FLAGS} xtrlock

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL} -m 4775 ${WRKSRC}/xtrlock ${DESTDIR}${PREFIX}/bin/xtrlock
	${INSTALL_MAN} ${MAN_PAGE} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xtrlock.1

.include "../../x11/libX11/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
