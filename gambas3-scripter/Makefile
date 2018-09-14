# $NetBSD$

BUILD_DIRS=	app
GB_DEPENDS=	gambas3-runtime gambas3-devel
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-scripter-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	Gambas scripter

CHECK_FILES_SKIP+=	${PREFIX}/bin/gambas3.*
CHECK_FILES_SKIP+=	${PREFIX}/share/appdata/gambas3.appdata.xml

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
