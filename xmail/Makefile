# $NetBSD: Makefile,v 1.2 2004/04/13 22:03:00 poppnk Exp $
#

DISTNAME=	xmail-1.15
CATEGORIES=	mail
MASTER_SITES=	http://www.xmailserver.com/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.xmailserver.com/
COMMENT=	Show png icons on your desktop

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

.include "../../mk/bsd.prefs.mk"

EXT=bsd # Default one :)
.if ${OPSYS} == "Linux"
	.if    ${MACHINE_ARCH} == "i86pc"
		EXT="lnx"
	.elsif ${MACHINE_ARCH} == "sparc"
		EXT="slx"
	.elsif ${MACHINE_ARCH} == "ppc"
		EXT="plx"
	.endif
.elsif ${OPSYS} == "Solaris"
	.if    ${MACHINE_ARCH} == "sparc"
		EXT="sso"
	.elsif ${MACHINE_ARCH} == "i86pc"
		EXT="ssx"
	.endif
.endif

MAKEFILE=Makefile.${EXT}

.include "../../mk/bsd.pkg.mk"
