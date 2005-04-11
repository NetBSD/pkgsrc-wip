# $NetBSD: Makefile,v 1.3 2005/04/11 21:16:14 tvierling Exp $
#

DISTNAME=	wmnetload-1.0
CATEGORIES=	x11 sysutils
MASTER_SITES=	http://dockapps.org/files/78/116/

MAINTAINER=		poff@sixbit.org
COMMENT=		Windowmaker dockapp to monitor network interface usage

USE_X11=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libs-from=${PREFIX}/lib

.include "../../devel/libdockapp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
