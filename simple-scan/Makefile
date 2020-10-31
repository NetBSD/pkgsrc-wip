# $NetBSD: Makefile,v 1.5 2014/06/01 12:49:48 thomasklausner Exp $
#

DISTNAME=	simple-scan-3.38.1
CATEGORIES=	graphics
MASTER_SITES=	https://gitlab.gnome.org/GNOME/simple-scan/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/simple-scan/
COMMENT=	Simple scanner graphical interface
LICENSE=	gnu-gpl-v3

USE_TOOLS=	pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/colord/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../pkgtools/packagekit/buildlink3.mk"
.include "../../wip/libgusb/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
