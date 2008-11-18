# $NetBSD: Makefile,v 1.2 2008/11/18 08:02:34 tonnerre Exp $
#

DISTNAME=	dillo-2.0
CATEGORIES=	www
MASTER_SITES=	http://www.dillo.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://www.dillo.org/
COMMENT=	Very small and fast graphical web browser using FLTK2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=		perl:run
REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	/usr/bin/perl
REPLACE.perl.new=	${TOOLS_PATH.perl}
REPLACE_FILES.perl=	dpid/dpidc

.include "../../x11/fltk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
