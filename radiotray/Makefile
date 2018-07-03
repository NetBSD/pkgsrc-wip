# $NetBSD: Makefile,v 1.8 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=	radiotray-0.6.3
PKGREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=radiotray/}
LICENSE=	gnu-gpl-v1

MAINTAINER=	pouya@san-serriffe.org
HOMEPAGE=	http://radiotray.sourceforge.net/
COMMENT=	Internet radio player with a minimal GUI

DEPENDS+=	${PYPKGPREFIX}-lxml>=2.1.5:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=	gst-plugins0.10-soup-[0-9]*:../../net/gst-plugins0.10-soup
DEPENDS+=	${PYPKGPREFIX}-notify-[0-9]*:../../sysutils/py-notify
# XXX notification-daemon is not a strict dependency.
#DEPENDS+=	notification-daemon-[0-9]*:../../sysutils/notification-daemon

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-notify, py-gtk2, py-gstreamer0.10, py-gobject

USE_TOOLS+=	xgettext

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		setup.cfg
SUBST_FILES.fix-paths+=		src/lib/*.py
SUBST_SED.fix-paths=		-e 's,/usr,'${PREFIX}',g'

.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
