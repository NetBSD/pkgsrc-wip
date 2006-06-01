# $NetBSD: Makefile,v 1.1.1.1 2006/06/01 12:03:23 lkundrak Exp $

DISTNAME=		sysjail-0.2.2
CATEGORIES=		sysutils
MASTER_SITES=		http://sysjail.bsd.lv/dist/

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://sysjail.bsd.lv/
COMMENT=		User-space replacement of FreeBSD jail

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

WRKSRC=			${WRKDIR}/sysjail-0.2.2
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

pre-extract:
.if !exists(${NETBSDSRCDIR}/sys/sys/systrace.h)
PKG_FAIL_REASON+="Need a kernel source tree in ${NETBSDSRCDIR}/sys."
PKG_FAIL_REASON+="Or set NETBSDSRCDIR correctly in /etc/mk.conf.)"
.endif

pre-build:
	${LN} -fs ${NETBSDSRCDIR}/sys/sys/systrace.h ${BUILDLINK_DIR}/include

.include "../../mk/bsd.pkg.mk"
