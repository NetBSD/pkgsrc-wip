# $NetBSD: Makefile,v 1.1.1.1 2004/03/28 04:41:43 xtraeme Exp $
#

DISTNAME=	howl-0.9.4
CATEGORIES=	net
MASTER_SITES=	http://www.porchdogsoft.com/download/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.porchdogsoft.com/download/
COMMENT=	Cross-platform implementation of the Zeroconf

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	howl.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
