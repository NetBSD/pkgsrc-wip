# $NetBSD: Makefile,v 1.2 2004/04/11 20:57:06 blef Exp $
#

DISTNAME=	wmnetload-1.0
CATEGORIES=	x11 sysutils
MASTER_SITES=	http://dockapps.org/files/78/116/

MAINTAINER=		poff@sixbit.org
COMMENT=		Windowmaker dockapp to monitor network interface usage

USE_BUILDLINK3=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libs-from=${PREFIX}/lib

.include "../../devel/libdockapp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
