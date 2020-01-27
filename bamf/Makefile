# $NetBSD: Makefile,v 1.13 2015/06/06 18:48:10 krytarowski Exp $
#

DISTNAME=	bamf-0.5.4
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://launchpad.net/bamf/0.5/${PKGVERSION_NOREV}/+download/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://launchpad.net/bamf/
COMMENT=	DBus daemon and C wrapper library of applications matching framework
LICENSE=	gnu-lgpl-v3

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config gsed

PYTHON_VERSIONS_ACCEPTED=	27

REPLACE_BASH+=	data/bamfdaemon-dbus-runner.in

DEPENDS+=	${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2
DEPENDS+=	${PYPKGPREFIX}-libxslt-[0-9]*:../../textproc/py-libxslt

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
