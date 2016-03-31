# $NetBSD: Makefile,v 1.8 2015/04/09 20:38:32 krytarowski Exp $

DISTNAME=	mate-themes-1.9.0
CATEGORIES=	graphics
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.9/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
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
