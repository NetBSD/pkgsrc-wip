# $NetBSD: Makefile,v 1.1.1.1 2003/07/02 14:56:51 poppnk Exp $
#

DISTNAME=	xmail-1.15
CATEGORIES=	mail
MASTER_SITES=	http://www.xmailserver.com/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.xmailserver.com/
COMMENT=	Show png icons on your desktop

USE_BUILDLINK2=	yes
NOT_FOR_PLATFORM=	NetBSD-*-*   # pthread & readdir_r miss-features :(

.include "../../mk/bsd.prefs.mk"
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
.elsif ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
	EXT="bsd"
.endif

MAKEFILE=Makefile.${EXT}

.include "../../mk/bsd.pkg.mk"
