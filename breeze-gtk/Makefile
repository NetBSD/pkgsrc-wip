# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	breeze-gtk-${PLASMAVER}
CATEGORIES=	misc

HOMEPAGE=	https://quickgit.kde.org/?p=breeze-gtk.git
COMMENT=	Breeze widget theme for GTK 2 and 3
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma5.mk"

TOOL_DEPENDS+=	sassc-[0-9]*:../../www/sassc
TOOL_DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-configure:
	ln -s ${PREFIX}/share/color-schemes ${BUILDLINK_DIR}/share/color-schemes

.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/breeze/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
