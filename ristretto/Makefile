# $NetBSD: Makefile,v 1.2 2012/10/07 14:53:43 asau Exp $

.include "../../wip/xfce48/Makefile.common"

RISTRETTO_VERSION=	0.0.93

DISTNAME=	ristretto-${RISTRETTO_VERSION}
#PKGREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	martin@NetBSD.org
HOMEPAGE=	http://goodies.xfce.org/projects/applications/ristretto
COMMENT=	Xfce image viewer
LICENSE=	gnu-gpl-v2

MASTER_SITES=	http://archive.xfce.org/src/apps/ristretto/0.0/

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config msgfmt perl intltool

.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
