# $NetBSD: $

DISTNAME=	lightdm-gtk-greeter-2.0.8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=Xubuntu/}
GITHUB_RELEASE=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/lightdm-gtk-greeter
COMMENT=	GTK+ greeter for LightDM
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS=		gmake intltool msgfmt msgmerge pkg-config xgettext
ICON_THEMES=		yes

DEPENDS=	gnome-icon-theme-[0-9]*:../../graphics/gnome-icon-theme
TOOL_DEPENDS=	xfce4-dev-tools-[0-9]*:../../devel/xfce4-dev-tools

PKG_SYSCONFSUBDIR=	lightdm
EGDIR=			${PREFIX}/share/examples
INSTALLATION_DIRS+=	${EGDIR}/lightdm
CONF_FILES+=		${EGDIR}/lightdm/lightdm-gtk-greeter.conf ${PKG_SYSCONFDIR}/lightdm-gtk-greeter.conf

pre-install:
	${INSTALL_DATA} ${WRKSRC}/data/lightdm-gtk-greeter.conf ${DESTDIR}${EGDIR}/lightdm/lightdm-gtk-greeter.conf

post-install:
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/lightdm-gtk-greeter.conf

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/lightdm/buildlink3.mk" # s,wip,x11,

.include "../../mk/bsd.pkg.mk"
