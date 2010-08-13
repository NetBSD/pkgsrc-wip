# $NetBSD: Makefile,v 1.6 2010/08/13 16:41:29 jihbed Exp $
#

DISTNAME=	d-feet-0.1.11
EGG_NAME=	d_feet-0.1.11
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://johnp.fedorapeople.org/downloads/d-feet/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://fedorahosted.org/d-feet/
COMMENT=	D-Feet is a powerful dbus debugger
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/share/dfeet,${PREFIX}/share/dfeet,g'
SUBST_SED.paths+=	-e 's,/usr/share/gnome/dfeet,${PREFIX}/share/gnome/dfeet,g'
SUBST_SED.paths+=	-e 's,/usr/share/dfeet/pixmaps,${PREFIX}/share/dfeet/pixmaps,g'
SUBST_SED.paths+=	-e 's,/usr/share/locale,${PREFIX}/share/locale,g'
SUBST_FILES.paths+=	d-feet${PYVERSSUFFIX}
SUBST_MESSAGE.paths=	Fixing header search paths.

post-extract:
	${MV} ${WRKSRC}/d-feet ${WRKSRC}/d-feet${PYVERSSUFFIX}

.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-dbus+=	${PYPKGPREFIX}-dbus>=0.23.4
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
