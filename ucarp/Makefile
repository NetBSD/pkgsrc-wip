# $NetBSD: Makefile,v 1.2 2004/06/13 19:57:42 ppostma Exp $
#

DISTNAME=		ucarp-0.8
CATEGORIES=		net
MASTER_SITES=		http://www.pureftpd.org/ucarp/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ucarp.org/
COMMENT=		Common Address Redundancy Protocol (CARP) for Unix

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

USE_BUILTIN.libpcap=	no

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
