# $NetBSD: Makefile,v 1.7 2015/04/09 20:38:32 krytarowski Exp $

.include "../../wip/mate/Makefile.common"

DISTNAME=	mate-sensors-applet-${MATE_VERSION}
CATEGORIES=	sysutils

COMMENT=	MATE Sensors applets

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt # for xsltproc

#SUBST_CLASSES+=	dl
#SUBST_STAGE.dl=	pre-configure
#SUBST_SED.dl=	-e 's,-ldl,${DL_LIBS:M*:Q},g'
#SUBST_FILES.dl=	sensors-applet/Makefile.in

.include "../../devel/glib2/schemas.mk"

.include "../../wip/mate-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
