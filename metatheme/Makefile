# $NetBSD: Makefile,v 1.2 2003/12/06 17:35:55 marc Exp $
#

DISTNAME=		metatheme-0.9.7
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/metatheme/0.9/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Themes for GNOME 2

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
BUILD_USES_MSGFMT=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../textproc/intltool/buildlink2.mk"
.include "../../x11/gnome2-control-center/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
