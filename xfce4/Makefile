# $NetBSD: Makefile,v 1.1.1.1 2003/06/04 07:42:55 marttikuparinen Exp $

.include "Makefile.common"

PKGNAME=	xfce4-${XFCE4_VERSION}
COMMENT=	XFce4

NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:	# empty

.include "../../wip/gtk2-engines-xfce/buildlink2.mk"
.include "../../wip/xfce4-desktop/buildlink2.mk"
.include "../../wip/xfce4-fm/buildlink2.mk"
.include "../../wip/xfce4-iconbox/buildlink2.mk"
.include "../../wip/xfce4-panel/buildlink2.mk"
.include "../../wip/xfce4-print/buildlink2.mk"
.include "../../wip/xfce4-utils/buildlink2.mk"
.include "../../wip/xfce4-wm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
