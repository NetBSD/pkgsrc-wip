# $NetBSD: Makefile,v 1.2 2003/06/30 00:10:12 xtraeme Exp $
#

DISTNAME=		gnome-themes-2.2
PKGNAME=		${DISTNAME:S/gnome/gnome2/}
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-themes/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jrp@hispabsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Collection of themes and icons for GNOME 2

DEPENDS+=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../wm/metacity/buildlink2.mk"
.include "../../x11/gtk2-engines/buildlink2.mk"
.include "../../wip/gtk2-thinice-engine/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
