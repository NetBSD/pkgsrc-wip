# $NetBSD: Makefile,v 1.9 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	hijra-0.1.18
PKGREVISION=	2
CATEGORIES=	python time
MASTER_SITES=	http://www.ojuba.org/downloads/hijra/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://hijra.ojuba.org/
COMMENT=	Hijra is the Hijri Islamic Calendar
#LICENSE=	LICENSE

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-notify, py-gtk2, py-gobject

INSTALLATION_DIRS+=	bin

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/HijriApplet.py ${DESTDIR}${PREFIX}/bin/HijriApplet

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-notify-[0-9]*:../../sysutils/py-notify
.include "../../x11/py-gnome2-extras/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
