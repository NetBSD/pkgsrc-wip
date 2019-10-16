# $NetBSD$

DISTNAME=	flpsed-0.7.3
CATEGORIES=	graphics
MASTER_SITES=	http://flpsed.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flpsed.org/
COMMENT=	Postscript and PDF annotator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gs:run

# FLTK version 1.4 is supported too
#.include "../../x11/fltk13/buildlink3.mk"
.include "../../wip/fltk14-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
