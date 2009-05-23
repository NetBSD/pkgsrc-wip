# $NetBSD: Makefile,v 1.1.1.1 2009/05/23 15:22:44 jihbed Exp $
#

DISTNAME=	d-feet-0.1.8
CATEGORIES=	devel python
MASTER_SITES=	http://johnp.fedorapeople.org/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://fedorahosted.org/d-feet/
COMMENT=	D-Feet is a powerful D-Bus debugger
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=		user-destdir

USE_TOOLS+=		msgfmt
USE_DIRS+= 		xdg-1.4
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 25

PYDISTUTILSPKG=		yes

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-dbus+=	${PYPKGPREFIX}-dbus>=0.23.4
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
