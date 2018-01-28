# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:35 asau Exp $
#

DISTNAME=	gjs-1.44.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gjs/1.44/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Gjs
COMMENT=	Javascript binding for GNOME besed on Spidermonkey
LICENSE=	mit

MAKE_JOBS_SAFE=		NO

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	gjs-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gjs-dbus-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gjs-gi-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gjs-internals-1.0.pc.in

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing dynamic python
SUBST_FILES.fix-python+=	scripts/make-tests
SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'

#SUBST_CLASSES+=		libjs
#SUBST_STAGE.libjs=		pre-configure
#SUBST_MESSAGE.fix-python=	Convert libjs to libmozjs24
#SUBST_FILES.fix-python+=	scripts/make-tests
#SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'

BUILDLINK_TRANSFORM+=	l:mozjs:mozjs24

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../wip/spidermonkey24/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
