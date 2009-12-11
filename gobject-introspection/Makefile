# $NetBSD: Makefile,v 1.2 2009/12/11 16:05:20 jihbed Exp $
#

DISTNAME=	gobject-introspection-0.6.6
CATEGORIES=	wip
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/gobject-introspection/0.6/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://live.gnome.org/GObjectIntrospection
COMMENT=	GObject Introspection
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../wip/py-cElementTree

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config flex bison gmake

PKGCONFIG_OVERRIDE+=	gobject-introspection-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gobject-introspection-no-export-1.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
