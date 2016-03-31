# $NetBSD: Makefile,v 1.5 2015/04/09 20:38:31 krytarowski Exp $

DISTNAME=	mate-netspeed-1.12.0
CATEGORIES=	net sysutils
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.12/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE little applet for network traffic information
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=		libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

.include "../../devel/glib2/schemas.mk"

.include "../../wip/mate-panel/buildlink3.mk"
.include "../../wip/mate-desktop/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
