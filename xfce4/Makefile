# $NetBSD: Makefile,v 1.10 2003/08/25 10:10:39 marttikuparinen Exp $

.include "Makefile.common"

DISTNAME=	xfce4-${XFCE4_VERSION}
DISTFILES=	# empty
CATEGORIES=	meta-pkgs
COMMENT=	XFce4

NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:	# empty

# Basic stuff
.include "../../wip/xfce4-desktop/buildlink2.mk"
.include "../../wip/xfce4-fm/buildlink2.mk"
.include "../../wip/xfce4-gtk2-engines/buildlink2.mk"
.include "../../wip/xfce4-iconbox/buildlink2.mk"
.include "../../wip/xfce4-panel/buildlink2.mk"
.include "../../wip/xfce4-print/buildlink2.mk"
.include "../../wip/xfce4-utils/buildlink2.mk"
.include "../../wip/xfce4-wm/buildlink2.mk"

# Extras
.include "../../wip/xfce4-fm-icons/buildlink2.mk"
## .include "../../wip/xfce4-minicmd-plugin/buildlink2.mk"
.include "../../wip/xfce4-mixer/buildlink2.mk"
## .include "../../wip/xfce4-netload-plugin/buildlink2.mk"
## .include "../../wip/xfce4-showdesktop-plugin/buildlink2.mk"
## .include "../../wip/xfce4-systemload-plugin/buildlink2.mk"
.include "../../wip/xfce4-systray/buildlink2.mk"
.include "../../wip/xfce4-themes/buildlink2.mk"
.include "../../wip/xfce4-toys/buildlink2.mk"
.include "../../wip/xfce4-trigger-launcher/buildlink2.mk"
.include "../../wip/xfce4-wm-themes/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
