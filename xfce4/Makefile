# $NetBSD: Makefile,v 1.2 2003/06/04 11:45:50 marttikuparinen Exp $

.include "Makefile.common"

PKGNAME=	xfce4-${XFCE4_VERSION}
COMMENT=	XFce4

NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:	# empty

# Basic stuff
.include "../../wip/gtk2-engines-xfce/buildlink2.mk"
.include "../../wip/xfce4-desktop/buildlink2.mk"
.include "../../wip/xfce4-fm/buildlink2.mk"
.include "../../wip/xfce4-iconbox/buildlink2.mk"
.include "../../wip/xfce4-panel/buildlink2.mk"
.include "../../wip/xfce4-print/buildlink2.mk"
.include "../../wip/xfce4-utils/buildlink2.mk"
.include "../../wip/xfce4-wm/buildlink2.mk"

# Extras
.include "../../wip/xfce4-fm-icons/buildlink2.mk"
.include "../../wip/xfce4-mixer/buildlink2.mk"
.include "../../wip/xfce4-systray/buildlink2.mk"
.include "../../wip/xfce4-themes/buildlink2.mk"
.include "../../wip/xfce4-toys/buildlink2.mk"
.include "../../wip/xfce4-trigger-launcher/buildlink2.mk"
.include "../../wip/xfce4-wm-themes/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
