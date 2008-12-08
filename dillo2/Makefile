# $NetBSD: Makefile,v 1.3 2008/12/08 07:58:15 tonnerre Exp $
#

DISTNAME=	dillo-2.0
CATEGORIES=	www
MASTER_SITES=	http://www.dillo.org/download/
PKGREVISION=	1
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

.include "options.mk"
.include "../../x11/fltk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
