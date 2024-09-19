# $NetBSD$

DISTNAME=	yad-0.40.0
CATEGORIES=	x11
MASTER_SITES=	https://downloads.sourceforge.net/yad-dialog/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	robn@gmx.com
HOMEPAGE=	https://downloads.sourceforge.net/yad-dialog/
COMMENT=	Tool for creating graphical dialogs from shell scripts
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake gmake intltool pkg-config

CONFIGURE_ARGS+=	--enable-icon-browser

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
