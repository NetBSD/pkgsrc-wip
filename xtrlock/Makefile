# $NetBSD: Makefile,v 1.1.1.1 2007/03/28 07:19:42 uhabel Exp $
#

DISTNAME=	xtrlock_2.0-12
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xtrlock/}

MAINTAINER=	uli@habel.name
HOMEPAGE=	${MASTER_SITE_DEBIAN:=pool/main/x/xtrlock/}
COMMENT=	Simple X11 screen lock tool

USE_IMAKE=	yes

WRKSRC=		${WRKDIR}/xtrlock-2.0
MAN_PAGE=	${WRKSRC}/xtrlock.man

do-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} ${MAKE_FLAGS} xtrlock

do-install:
	${INSTALL} -m 4775 ${WRKSRC}/xtrlock ${PREFIX}/bin/xtrlock
	${INSTALL_MAN} ${MAN_PAGE} ${PREFIX}/${PKGMANDIR}/man1/xtrlock.1

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
