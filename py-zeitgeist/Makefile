# $NetBSD: Makefile,v 1.13 2014/01/25 10:38:23 thomasklausner Exp $

DISTNAME=	zeitgeist-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/zeitgeist/0.3/0.3.2/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/zeitgeist/
COMMENT=	Service which logs the users's activities and events
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-storm-[0-9]*:../../wip/py-storm

FETCH_USING=	curl
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	gmake intltool
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-ORBit via py-gnome2, py-gtk2

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.14.1nb1
.include "../../x11/py-gtk2/buildlink3.mk"
# for py-gconf
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
