# $NetBSD: Makefile,v 1.6 2014/05/09 07:38:44 thomasklausner Exp $

DISTNAME=	pessulus-2.30.0
PKGREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pessulus/2.30/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://live.gnome.org/Pessulus
COMMENT=	Pessulus is a lockdown editor for GNOME
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake intltool msgfmt
USE_LANGUAGES=		c

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-gtk2, py-gobject

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.py-gnome2-desktop+=	${PYPKGPREFIX}-gnome2-desktop>=2.16.0
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.8.4
.include "../../x11/py-gtk2/buildlink3.mk"
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
