# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:07 thomasklausner Exp $
#

DISTNAME=	hijra-0.1.18
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	http://www.ojuba.org/downloads/hijra/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://hijra.ojuba.org/
COMMENT=	Hijra is the Hijri Islamic Calendar
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=		yes


INSTALLATION_DIRS+=	bin

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/HijriApplet.py ${DESTDIR}${PREFIX}/bin/HijriApplet

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../sysutils/py-notify/buildlink3.mk"
.include "../../x11/py-gnome2-extras/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
