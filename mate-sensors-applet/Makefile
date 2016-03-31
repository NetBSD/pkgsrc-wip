# $NetBSD: Makefile,v 1.7 2015/04/09 20:38:32 krytarowski Exp $

DISTNAME=	mate-sensors-applet-1.12.1
CATEGORIES=	sysutils
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.12/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE Sensors applets
LICENSE=	gnu-gpl-v2 AND cc-by-sa-v3.0

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt # for xsltproc

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

SUBST_CLASSES+=	dl
SUBST_STAGE.dl=	pre-configure
SUBST_SED.dl=	-e 's,-ldl,${DL_LIBS},g'
SUBST_FILES.dl=	sensors-applet/Makefile.in

.include "../../devel/glib2/schemas.mk"

.include "../../wip/mate-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
