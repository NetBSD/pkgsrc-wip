# $NetBSD: Makefile,v 1.1.1.1 2010/03/09 23:01:32 othyro Exp $
#

DISTNAME=	flpsed-0.6.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/
COMMENT=	WYSIWYG PostScript annotator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/fltk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
