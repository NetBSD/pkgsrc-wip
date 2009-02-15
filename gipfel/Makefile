# $NetBSD: Makefile,v 1.5 2009/02/15 08:11:00 obache Exp $
#

DISTNAME=	gipfel-0.2.6
CATEGORIES=	geography graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/
COMMENT=	Georeferencing software for arbitrary images

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

DEPENDS+=	exif-[0-9]*:../../graphics/exif

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
