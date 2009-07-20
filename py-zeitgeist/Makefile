# $NetBSD: Makefile,v 1.2 2009/07/20 10:55:48 thomasklausner Exp $
#

DISTNAME=	zeitgeist-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	http://edge.launchpad.net/zeitgeist/0.2/0.2/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/zeitgeist/
COMMENT=	Service which logs the users's activities and events
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-storm-[0-9]*:../../wip/py-storm

PYTHON_VERSIONS_INCOMPATIBLE=	23 24 25

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	gmake intltool
PY_PATCHPLIST=	yes

REPLACE_PYTHON=	zeitgeist-daemon zeitgeist-datahub

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.14.1nb1
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
