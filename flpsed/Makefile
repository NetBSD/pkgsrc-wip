# $NetBSD: Makefile,v 1.4 2012/06/03 23:03:31 othyro Exp $
#

DISTNAME=	flpsed-0.7.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/
COMMENT=	WYSIWYG PostScript annotator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gs:run

.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
