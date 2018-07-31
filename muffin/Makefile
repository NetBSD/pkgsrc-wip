# $NetBSD: Makefile,v 1.17 2013/06/17 12:45:12 thomasklausner Exp $

DISTNAME=	muffin-3.8.1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	muffin
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/linuxmin/muffin
COMMENT=	Cinnamon window manager
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool automake msgfmt pkg-config autoreconf

BUILD_DEPENDS+=		autoconf-archive-[0-9]*:../../devel/autoconf-archive
BUILD_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4
DEPENDS+=		zenity-[0-9]*:../../x11/zenity

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=1 ./autogen.sh

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"

.include "../../wip/cinnamon-desktop/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
