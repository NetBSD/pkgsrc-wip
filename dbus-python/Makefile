# $NetBSD: Makefile,v 1.2 2006/01/17 09:13:38 rillig Exp $
#

DBUS_INTERFACE=	python
DBUS_DIRS=	dbus glib python tools

.include "../../sysutils/dbus/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex

# We can't install from within the 'dbus' nor 'tools' directory automatically
# because we'd get a lot of other stuff installed (overriding files in the
# dbus package).
INSTALL_DIRS=	python

.include "../../lang/python/pyversion.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
