# $NetBSD: Makefile,v 1.4 2006/09/18 18:20:42 dhowland Exp $
#

DISTNAME=		scim-1.4.4
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=		rxg@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		Smart Common Input Method

PKG_SYSCONFSUBDIR=	scim

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config
USE_TOOLS+=		gmake	# make scim-setup.desktop
USE_TOOLS+=		perl intltool
PKGCONFIG_OVERRIDE=	scim-gtkutils.pc.in
PKGCONFIG_OVERRIDE+=	scim-x11utils.pc.in
PKGCONFIG_OVERRIDE+=	scim.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
GTK2_IMMODULES=		yes

.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples/scim
CONF_FILES=		${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=		${EGDIR}/global ${PKG_SYSCONFDIR}/global

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
