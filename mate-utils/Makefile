# $NetBSD: Makefile,v 1.8 2015/04/09 20:38:32 krytarowski Exp $

DISTNAME=	mate-utils-1.12.0
CATEGORIES=	misc
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.12/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Utiltiles for MATE Desktop
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.1 AND gnu-lgpl-v2.1

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config grep:run

PKGCONFIG_OVERRIDE+=	mate-dictionary/libgdict/mate-dict.pc.in

CONFIGURE_ARGS+=	--with-grep=${GREP}

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../wip/mate-panel/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
