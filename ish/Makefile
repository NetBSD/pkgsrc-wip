# $NetBSD: Makefile,v 1.1.1.1 2003/07/04 03:14:18 poppnk Exp $
#

DISTNAME=	ish-v${VERSION}
PKGNAME=	ish-${VERSION}
WRKSRC=		${WRKDIR}/ISHELL-v${VERSION}/
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icmpshell/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://ish.sourceforge.net/
COMMENT=	Allow remote shell using ICMP

VERSION=	0.2

USE_GMAKE=	yes
USE_BUILDLINK2=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
ALL_TARGET=linux
.elsif ${OPSYS} == "Solaris"
ALL_TARGET=solaris
.else
ALL_TARGET=bsd
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ish  ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ishd ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
