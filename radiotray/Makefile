# $NetBSD: Makefile,v 1.1.1.1 2011/03/08 14:04:22 pdtafti Exp $
#

DISTNAME=		radiotray-0.6.3
CATEGORIES=		audio net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=radiotray/}
LICENSE=		gnu-gpl-v2

MAINTAINER=		pouya@san-serriffe.org
HOMEPAGE=		http://radiotray.sourceforge.net/
COMMENT=		Internet radio player with a minimal GUI

DEPENDS+=		${PYPKGPREFIX}-lxml>=2.1.5:../../textproc/py-lxml
DEPENDS+=		${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=		gst-plugins0.10-soup-[0-9]*:../../net/gst-plugins0.10-soup
DEPENDS+=		notification-daemon-[0-9]*:../../sysutils/notification-daemon

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=			yes

USE_TOOLS+=				xgettext

SUBST_CLASSES+=				fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		setup.cfg
SUBST_FILES.fix-paths+=		src/lib/*.py
SUBST_SED.fix-paths=		-e 's,/usr,'${PREFIX}',g'

.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../sysutils/py-notify/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
