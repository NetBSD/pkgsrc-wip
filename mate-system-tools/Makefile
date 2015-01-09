# $NetBSD: Makefile,v 1.2 2015/01/09 10:50:16 obache Exp $

DISTNAME=	mate-system-tools-1.8.1
CATEGORIES=	sysutils
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.8/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE System Tools
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	mate-system-tools.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

PKG_SYSCONFSUBDIR=	${PKGBASE}
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/user-profiles.conf \
		${PKG_SYSCONFDIR}/user-profiles.conf

.include "../../devel/glib2/schemas.mk"

.include "../../wip/mate-polkit/buildlink3.mk"
.include "../../wip/caja/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../wip/liboobs/buildlink3.mk"
.include "../../wip/system-tools-backends/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
