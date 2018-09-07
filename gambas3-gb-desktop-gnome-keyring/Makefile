# $NetBSD$

BUILD_DIRS=	gb.desktop.gnome.keyring
GB_DEPENDS=	gambas3-gb-desktop
.include "../../wip/gambas3/Makefile.common"

PKGNAME=	gambas3-gb-desktop-gnome-keyring-${GB_VERSION}
MAINTAINER=	bastiangermann@fishpost.de
COMMENT=	Gnome keyring support for Gambas desktop component (deprecated)

.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
