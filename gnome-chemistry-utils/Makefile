# $NetBSD: Makefile,v 1.2 2010/05/12 15:09:23 jihbed Exp $
#

DISTNAME=	gnome-chemistry-utils-0.11.98
CATEGORIES=	biology
MASTER_SITES=	http://mirrors.fe.up.pt/pub/nongnu/gchemutils/0.11/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://gchemutils.nongnu.org/
COMMENT=	GChemPaint, a 2D chemical editor and other programs

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkgc-config perl msgfmt intltool
USE_LANGUAGES=	c c++

GCONF_SCHEMAS+=	gchemutils.schemas
GCONF_SCHEMAS+=	plugins/paint/arrows/gchempaint-arrows.schemas
GCONF_SCHEMAS+=	programs/crystal/gcrystal.schemas
GCONF_SCHEMAS+=	programs/paint/gchempaint.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
