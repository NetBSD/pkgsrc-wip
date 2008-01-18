# $NetBSD: Makefile,v 1.21 2008/01/18 04:30:18 tnn2 Exp $

.include "Makefile.common"

DISTNAME=	xfce4-${XFCE4_VERSION}
DISTFILES=	# empty
PKGREVISION=	2
CATEGORIES=	meta-pkgs
COMMENT=	Xfce

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)
WRKSRC=		${WRKDIR}

do-install:
	@${DO_NADA}

.include "../../wip/xfce4-mixer/buildlink3.mk"
.include "../../wip/xfce4-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-print/buildlink3.mk"
.include "../../wip/xfce4-appfinder/buildlink3.mk"
.include "../../wip/xfce4-xarchiver/buildlink3.mk"
.include "../../wip/xfce4-orage/buildlink3.mk"
.include "../../wip/xfce4-wm/buildlink3.mk"
.include "../../wip/xfce4-wm-themes/buildlink3.mk"
.include "../../wip/xfce4-desktop/buildlink3.mk"
.include "../../wip/xfce4-gtk2-engine/buildlink3.mk"
.include "../../wip/xfce4-mousepad/buildlink3.mk"
.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../wip/xfce4-session/buildlink3.mk"
.include "../../wip/xfce4-terminal/buildlink3.mk"
.include "../../wip/xfce4-utils/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
