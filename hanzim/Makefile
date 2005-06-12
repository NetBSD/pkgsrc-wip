# $NetBSD: Makefile,v 1.3 2005/06/12 23:51:20 kristerw Exp $
#

DISTNAME=	hanzim-1.3
CATEGORIES=	misc
MASTER_SITES=	ftp://kommos.ucsd.edu/pub/arobert/Chinese/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://zakros.ucsd.edu/~arobert/hanzim.html
COMMENT=	Chinese character learning-aid program

WRKSRC=		${WRKDIR}/Hanzim

pre-install:
	@if [ "$$DISPLAY" = "" ]; then \
		${ECHO} "${DISTNAME} can only be installed under X11."; \
		exit 1; \
	 fi

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
