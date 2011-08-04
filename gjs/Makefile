# $NetBSD: Makefile,v 1.1.1.1 2011/08/04 15:41:03 ryo-on Exp $
#

DISTNAME=	gjs-0.7.14
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gjs/0.7/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Gjs
COMMENT=	Javascript binding for GNOME besed on Spidermonkey
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

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

#SUBST_CLASSES+=			libjs
#SUBST_STAGE.libjs=		pre-configure
#SUBST_MESSAGE.fix-python=	Convert libjs to libmozjs185
#SUBST_FILES.fix-python+=	scripts/make-tests
#SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'

BUILDLINK_TRANSFORM+=	l:mozjs:mozjs185

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../wip/spidermonkey185/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
