# $NetBSD: Makefile,v 1.2 2004/05/07 01:57:56 xtraeme Exp $
#

DISTNAME=	howl-0.9.4
CATEGORIES=	net
MASTER_SITES=	http://www.porchdogsoft.com/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.porchdogsoft.com/download/
COMMENT=	Cross-platform implementation of the Zeroconf

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	howl.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
