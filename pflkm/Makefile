# $NetBSD: Makefile,v 1.5 2004/05/04 11:22:34 imilh Exp $
#

DISTNAME=		pflkm-3.4
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://imil.net/NetBSD/

MAINTAINER=		imil@gcu.info
HOMEPAGE=		http://foo.unix.se/joelw/pflkm.html
COMMENT=		Pf loadable kernel module for NetBSD

ONLY_FOR_PLATFORM=	NetBSD-2.0*-*

pre-install:
.if !exists(${PREFIX}/lkm)
	@${INSTALL_DATA_DIR} ${PREFIX}/lkm
.endif

post-install:
.if !exists(${PKG_SYSCONFBASE}/pf.os)
	${INSTALL_DATA} ${WRKSRC}/etc/pf.os ${PKG_SYSCONFBASE}
.endif

USE_BUILDLINK3=		yes

.include "../../mk/bsd.pkg.mk"
