# $NetBSD: Makefile,v 1.2 2005/04/11 21:12:59 tvierling Exp $
#

DISTNAME=	hanzim-1.3
CATEGORIES=	misc
MASTER_SITES=	ftp://kommos.ucsd.edu/pub/arobert/Chinese/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://zakros.ucsd.edu/~arobert/hanzim.html
COMMENT=	Chinese character learning-aid program

USE_X11=	yes

WRKSRC=		${WRKDIR}/Hanzim

pre-install:
	@if [ "$$DISPLAY" = "" ]; then \
		${ECHO} "${DISTNAME} can only be installed under X11."; \
		exit 1; \
	 fi

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
