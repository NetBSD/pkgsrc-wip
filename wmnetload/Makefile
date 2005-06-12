# $NetBSD: Makefile,v 1.4 2005/06/12 23:51:30 kristerw Exp $
#

DISTNAME=	wmnetload-1.0
CATEGORIES=	x11 sysutils
MASTER_SITES=	http://dockapps.org/files/78/116/

MAINTAINER=		poff@sixbit.org
COMMENT=		Windowmaker dockapp to monitor network interface usage

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libs-from=${PREFIX}/lib

.include "../../devel/libdockapp/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
