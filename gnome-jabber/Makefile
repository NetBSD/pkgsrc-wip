# $NetBSD: Makefile,v 1.13 2013/06/19 12:15:39 noud4 Exp $
#

DISTNAME=	gnome-jabber-0.4
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-jabber/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnome-jabber.sourceforge.net/
COMMENT=	Instant message client for Gnome using the Jabber protocol
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++ fortran
USE_TOOLS+=		msgfmt perl pkg-config xgettext

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF_SCHEMAS+=		gnome-jabber.schemas

.include "../../x11/libXScrnSaver/buildlink3.mk"
BUILD_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
.include "../../x11/libX11/buildlink3.mk"
BUILD_DEPENDS+=	glib2>=2.0.3:../../devel/glib2
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILD_DEPENDS+=	libglade>=2.0.0:../../devel/libglade
.include "../../devel/libglade/buildlink3.mk"
BUILD_DEPENDS+=	gtk2+>=2.0.4:../../x11/gtk2
.include "../../x11/gtk2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
BUILD_DEPENDS+=	libgnome>=2.0.0:../../devel/libgnome
.include "../../devel/libgnome/buildlink3.mk"
BUILD_DEPENDS+=	GConf>=1.2.0:../../devel/GConf
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
