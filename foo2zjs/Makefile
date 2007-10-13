# $NetBSD: Makefile,v 1.1 2007/10/13 20:50:49 martijnb Exp $
#

DISTNAME=	foo2zjs-20071007
CATEGORIES=	wip
MASTER_SITES=	http://www.stack.nl/~martijnb/foo2zjs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	martijn.van.buul@gmail.com
HOMEPAGE=	http://foo2zjs.rkkda.com/
COMMENT=	Printer driver for ZjStream-compatible printers

WRKSRC=	${WRKDIR}/foo2zjs

USE_TOOLS+=	gmake

INSTALL_TARGET= install-prog install-icc2ps install-man install-doc install-ppd

DEPENDS+= 	foomatic-filters>=3.0:../../print/foomatic-filters
DEPENDS+=       foomatic-ppds-[0-9]*:../../print/foomatic-ppds
.include "../../mk/bsd.pkg.mk"
