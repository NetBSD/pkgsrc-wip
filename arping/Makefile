# $NetBSD: Makefile,v 1.2 2004/04/25 04:30:59 blef Exp $
#

PKGNAME=		arping-1.08
DISTNAME=		arping-2.01
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		ftp://ftp.habets.pp.se/pub/synscan/
COMMENT=		ARP-level ping utility

USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
ALL_TARGET=		openbsd
.elif ${OPSYS} == "Linux"
ALL_TARGET=		linux
.elif ${OPSYS} == "FreeBSD"
ALL_TARGET=		freebsd
.elif ${OPSYS} == "SunOS"
ALL_TARGET=		solaris
.elif ${OPSYS} == "Darwin"
ALL_TARGET=		macosx
.endif

ONLY_FOR_PLATFORM=	NetBSD-* OpenBSD-* FreeBSD-*	\
			Linux-* SunOS-* Darwin-*

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
