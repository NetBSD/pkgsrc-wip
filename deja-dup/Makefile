# $NetBSD$

DISTNAME=	deja-dup-45.1
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.gnome.org/World/deja-dup/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/DejaDup
COMMENT=	Trivial-to-use personal backup tool
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c
USE_TOOLS+=		itstool pkg-config

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/deja-dup

INSTALLATION_DIRS+=	share/examples/xdg/autostart
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=		${PREFIX}/share/examples/xdg/autostart/org.gnome.DejaDup.Monitor.desktop \
			${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.DejaDup.Monitor.desktop
post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/autostart/org.gnome.DejaDup.Monitor.desktop \
		${DESTDIR}${PREFIX}/share/examples/xdg/autostart/

.include "../../devel/meson/build.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
