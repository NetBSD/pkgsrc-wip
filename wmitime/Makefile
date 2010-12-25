# $NetBSD: Makefile,v 1.10 2010/12/25 12:45:45 noud4 Exp $
#

DISTNAME=	wmitime-0.3
PKGREVISION=	2
CATEGORIES=	x11 sysutils
MASTER_SITES=	http://www.neotokyo.org/illusion/downloads/

MAINTAINER=	poff@sixbit.org
HOMEPAGE=	http://www.neotokyo.org/illusion/dock_apps.html
COMMENT=	Windowmaker dockapp for time/date/itime

WRKSRC=		${WRKDIR}/wmitime/wmitime

USE_TOOLS+=	gmake

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
