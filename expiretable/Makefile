# $NetBSD: Makefile,v 1.1.1.1 2007/12/21 10:29:25 bartoszkuzma Exp $
#

DISTNAME=	expiretable-0.6
CATEGORIES=	sysutils wip
MASTER_SITES=	http://expiretable.fnord.se/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://expiretable.fnord.se/
COMMENT=	Removes entries from pf tables based on their age

ONLY_FOR_PLATFORM=	DragonFly-*-* FreeBSD-[5-9]*-*
ONLY_FOR_PLATFORM+=	NetBSD-[3-9]*-* OpenBSD-[4-9]*-*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/expiretable ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/expiretable.1 ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
