# $NetBSD: Makefile,v 1.1 2012/12/27 05:41:58 othyro Exp $
#

DISTNAME=	gtksourceviewmm-3.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceviewmm/3.2/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.gnome.org/gtksourceviewmm/stable/
COMMENT=	C++ wrapper for the gtksourceview widget library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/gtksourceviewmm-3.2.0
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	gtksourceview/gtksourceviewmm.pc.in

BUILD_DEPENDS+=	atkmm-[0-9]*:../../devel/atkmm
BUILD_DEPENDS+=	cairomm-[0-9]*:../../graphics/cairomm
BUILD_DEPENDS+= glibmm-[0-9]*:../../devel/glibmm
BUILD_DEPENDS+=	glib2-[0-9]*:../../devel/glib2
BUILD_DEPENDS+=	pangomm-[0-9]*:../../devel/pangomm
BUILD_DEPENDS+=	libsigc++-[0-9]*:../../devel/libsigc++
.include "../../wip/gtkmm3/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
