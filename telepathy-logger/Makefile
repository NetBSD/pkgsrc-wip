# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:50 thomasklausner Exp $
#

DISTNAME=	telepathy-logger-0.1.1
CATEGORIES=	chat gnome
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-logger/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Logger
COMMENT=	The logging of all communication within the Telepathy framework
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

CONFIGURE_ARGS+=	--disable-Werror
CONFIGURE_ARGS+=	--disable-channeltext
CONFIGURE_ARGS+=	--disable-coding-style-checks

PKGCONFIG_OVERRIDE+=	telepathy-logger/telepathy-logger.pc.in

PYTHON_VERSIONS_ACCEPTED= 27 26 25

BUILDLINK_API_DEPENDS.telepathy-glib+=	telepathy-glib>=0.7.18
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
