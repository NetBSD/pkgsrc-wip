# $NetBSD: Makefile,v 1.1.1.1 2004/07/18 15:53:38 cetrox Exp $
#

DISTNAME=		chbg-1.5
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=chbg/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://chbg.sourceforge.net/
COMMENT=		Changes destop background pictures with some period

DEPENDS+=		ImageMagick>=6.0.2.7:../../graphics/ImageMagick

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-image-library=imlib2

pre-configure:
		${CP} ${FILESDIR}/es.* ${WRKSRC}/po

.include "../../devel/glib/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
