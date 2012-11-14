# $NetBSD: Makefile,v 1.5 2012/11/14 00:16:05 othyro Exp $
#

DISTNAME=	foo2zjs-20080105
CATEGORIES=	print
MASTER_SITES=	http://www.stack.nl/~martijnb/foo2zjs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	martijn.van.buul@gmail.com
HOMEPAGE=	http://foo2zjs.rkkda.com/
COMMENT=	Printer driver for ZjStream-compatible printers

PKG_DESTDIR_SUPPORT=	none

WRKSRC=	${WRKDIR}/foo2zjs

USE_TOOLS+=	gmake

INSTALL_TARGET= install-prog install-icc2ps install-man install-doc install-ppd

DEPENDS+=	foomatic-filters>=3.0:../../print/foomatic-filters
DEPENDS+=	foomatic-ppds-[0-9]*:../../print/foomatic-ppds
.include "../../mk/bsd.pkg.mk"
