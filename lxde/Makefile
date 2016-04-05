# $NetBSD: $

META_PACKAGE=	yes

DISTNAME=	lxde-1.0

MAINTAINER=	youri@NetBSD.org
CATEGORIES=	meta-pkgs
COMMENT=	Lxde
LICENSE=	gnu-gpl-v2

DEPENDS+=	lxmenu-data-[0-9]*:../../wip/lxmenu-data
DEPENDS+=	lxappearance-[0-9]*:../../wip/lxappearance
#DEPENDS+=	lxappearance-obconf-[0-9]*:../../wip/lxappearance-obconf
DEPENDS+=	gpicview-[0-9]*:../../graphics/gpicview
DEPENDS+=	openbox-[0-9]*:../../wm/openbox
DEPENDS+=	lxpanel-[0-9]*:../../wip/lxpanel
DEPENDS+=	lxde-common-[0-9]*:../../wip/lxde-common
DEPENDS+=	menu-cache-[0-9]*:../../sysutils/menu-cache
DEPENDS+=	lxrandr-[0-9]*:../../wip/lxrandr
DEPENDS+=	lxterminal-[0-9]*:../../wip/lxterminal
DEPENDS+=	lxlauncher-[0-9]*:../../wip/lxlauncher
DEPENDS+=	lxsession-[0-9]*:../../wip/lxsession
DEPENDS+=	lxde-icon-theme-[0-9]*:../../wip/lxde-icon-theme
DEPENDS+=	pcmanfm-[0-9]*:../../wip/pcmanfm
DEPENDS+=	lxinput-[0-9]*:../../wip/lxinput
DEPENDS+=	lxtask-[0-9]*:../../wip/lxtask

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
DEPENDS+=	lxdm-[0-9]*:../../wip/lxdm
.endif

pre-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
