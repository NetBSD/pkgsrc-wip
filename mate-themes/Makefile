# $NetBSD: Makefile,v 1.7 2015/04/09 02:58:04 krytarowski Exp $

DISTNAME=	mate-themes-1.8.1
CATEGORIES=	graphics
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.8/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Icons and themes for MATE desktop
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	gtk2-engines-[0-9]*:../../x11/gtk2-engines
DEPENDS+=	gtk2-engines-murrine>=0.98.0:../../x11/gtk2-engines-murrine

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

CONFIGURE_ARGS+=	--enable-all-themes

.include "../../graphics/icon-naming-utils/buildlink3.mk"
BUILDLINK_DEPMETHOD.gdk-pixbuf2+=	build
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gtk2+=	build
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
