# $NetBSD: Makefile,v 1.5 2012/09/28 23:21:48 asau Exp $
#

DISTNAME=	flpsed-0.7.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/
COMMENT=	WYSIWYG PostScript annotator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gs:run

.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
