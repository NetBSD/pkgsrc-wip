# $NetBSD: Makefile,v 1.6 2015/04/09 22:07:27 krytarowski Exp $

.include "../../wip/mate/Makefile.common"

DISTNAME=	engrampa-${MATE_VERSION}
CATEGORIES=	archivers

COMMENT=	Archive manager utility for the MATE Environment

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

USE_TOOLS+=		gtar:run gzip:run bzip2:run unzip:run zip:run xz:run

.include "../../devel/glib2/schemas.mk"

.include "../../wip/caja/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_DEPMETHOD.libSM=	build
.include "../../x11/libSM/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
