# $NetBSD: Makefile,v 1.2 2014/04/24 22:16:46 thomasklausner Exp $

DISTNAME=	xfburn-0.5.2
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/apps/xfburn/0.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://goodies.xfce.org/projects/applications/xfburn
COMMENT=	Simple CD/DVD burning program for xfce
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/libburn/buildlink3.mk"
.include "../../wip/libisofs/buildlink3.mk"
.include "../../wip/libxfce4ui/buildlink3.mk"
.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
