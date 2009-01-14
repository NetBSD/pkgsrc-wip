# $NetBSD: Makefile,v 1.6 2009/01/14 13:42:41 obache Exp $
#

DISTNAME=		scim-1.4.7
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		Smart Common Input Method

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_SYSCONFSUBDIR=	scim

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config
USE_TOOLS+=		gmake	# make scim-setup.desktop
USE_TOOLS+=		perl intltool
USE_DIRS+=		gnome2-1.3

PKGCONFIG_OVERRIDE=	scim-gtkutils.pc.in
PKGCONFIG_OVERRIDE+=	scim-x11utils.pc.in
PKGCONFIG_OVERRIDE+=	scim.pc.in

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
GTK2_IMMODULES=		yes

EGDIR=			${PREFIX}/share/examples/scim
CONF_FILES=		${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=		${EGDIR}/global ${PKG_SYSCONFDIR}/global

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
