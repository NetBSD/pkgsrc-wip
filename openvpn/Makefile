# 
# $NetBSD: Makefile,v 1.1.1.1 2003/06/27 21:20:55 tripledes Exp $
#

DISTNAME=		openvpn-1.4.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openvpn/}

MAINTAINER=		tripledes@eslack.org
HOMEPAGE=		http://openvpn.sourceforge.net/
COMMENT=		Robust and highly configurable VPN

GNU_CONFIGURE=          yes
USE_PKGINSTALL= YES
USE_BUILDLINK2=	YES
CONFIGURE_ARGS+= --enable-pthread

.include "../../security/openssl/buildlink2.mk"
.include "../../archivers/liblzo/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
