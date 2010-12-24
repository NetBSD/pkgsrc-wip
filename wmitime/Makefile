# $NetBSD: Makefile,v 1.9 2010/12/24 18:31:47 noud4 Exp $
#

DISTNAME=	wmitime-0.3
PKGREVISION=	1
CATEGORIES=	x11 sysutils
MASTER_SITES=	http://www.neotokyo.org/illusion/downloads/

MAINTAINER=	poff@sixbit.org
HOMEPAGE=	http://www.neotokyo.org/illusion/dock_apps.html
COMMENT=	Windowmaker dockapp for time/date/itime

WRKSRC=		${WRKDIR}/wmitime/wmitime

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"
.if ${X11_TYPE} == "modular"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.else
.include "../../mk/x11.buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
