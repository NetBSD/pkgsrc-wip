# $NetBSD: Makefile,v 1.1.1.1 2004/04/29 20:52:10 xtraeme Exp $
#

DISTNAME=		ucarp-0.6
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
