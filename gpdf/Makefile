# $NetBSD: Makefile,v 1.1.1.1 2003/10/27 00:05:09 xtraeme Exp $
#

DISTNAME=	gpdf-0.111
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gpdf/0.111/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME 2 version of xpdf

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
