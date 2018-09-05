# $NetBSD$

BUILD_DIRS=	gb.qt4/src/webkit
GB_DEPENDS=	gambas3-gb-qt4
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-qt4-webkit-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	Web browser component for Gambas based on WebKit/Qt4

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
