# $NetBSD: Makefile,v 1.1.1.1 2003/08/03 16:48:54 amadeus_z Exp $
#

DISTNAME=	wmnetload-1.0
CATEGORIES=	x11 sysutils
MASTER_SITES=	http://dockapps.org/files/78/116/

MAINTAINER=		poff@sixbit.org
COMMENT=		Windowmaker dockapp to monitor network interface usage

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libs-from=${PREFIX}/lib

.include "../../devel/libdockapp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
