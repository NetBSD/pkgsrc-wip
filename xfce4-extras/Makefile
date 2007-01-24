# $NetBSD: Makefile,v 1.4 2007/01/24 08:53:06 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=	xfce4-extras-${XFCE4_VERSION}
DISTFILES=	# empty
#PKGREVISION=	1
CATEGORIES=	meta-pkgs
COMMENT=	Xfce extras

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes
WRKSRC=		${WRKDIR}

do-install:
	@${DO_NADA}

# Xfce
.include "../../wip/xfce4/buildlink3.mk"

#
# Do you want to have more plugins? See http://goodies.xfce.org/releases/
# for all available plugins...
#

# Additional plugins etc.
.include "../../wip/xfce4-xmms-plugin/buildlink3.mk"
.include "../../wip/xfce4-weather-plugin/buildlink3.mk"
.include "../../wip/xfce4-wavelan-plugin/buildlink3.mk"
.include "../../wip/xfce4-datetime-plugin/buildlink3.mk"
.include "../../wip/xfce4-cpugraph-plugin/buildlink3.mk"
.include "../../wip/xfce4-diskperf-plugin/buildlink3.mk"
.include "../../wip/xfce4-fsguard-plugin/buildlink3.mk"
.include "../../wip/xfce4-netload-plugin/buildlink3.mk"
.include "../../wip/xfce4-quicklauncher-plugin/buildlink3.mk"
.include "../../wip/xfce4-systemload-plugin/buildlink3.mk"
.include "../../wip/xfce4-xkb-plugin/buildlink3.mk"
.include "../../wip/xfce4-clipman-plugin/buildlink3.mk"
.include "../../wip/xfce4-notes-plugin/buildlink3.mk"

## WHAT TO DO WITH THESE?
# .include "../../graphics/xfce4-artwork/buildlink3.mk"

## CURRENTLY NO SUPPORT FOR 4.4
# .include "../../sysutils/xfce4-minicmd-plugin/buildlink3.mk"
# .include "../../sysutils/xfce4-showdesktop-plugin/buildlink3.mk"
# .include "../../x11/xfce4-taskbar-plugin/buildlink3.mk"
# .include "../../x11/xfce4-windowlist-plugin/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
