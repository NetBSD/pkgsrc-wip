# $NetBSD: Makefile,v 1.2 2003/06/25 08:48:51 xtraeme Exp $
#

DISTNAME=		yelp-2.2.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/yelp/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jrp@hispabsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Help browser for GNOME 2.0 desktop

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
