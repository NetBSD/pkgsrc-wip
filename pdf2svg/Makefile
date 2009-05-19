# $NetBSD: Makefile,v 1.2 2009/05/19 16:22:45 briandealwis Exp $
#

DISTNAME=	pdf2svg-0.2.1
CATEGORIES=	converters
MASTER_SITES=	http://www.cityinthesky.co.uk/files/

MAINTAINER=	bsd@cs.ubc.ca
HOMEPAGE=	http://www.cityinthesky.co.uk/files/
COMMENT=	Small utility to convert PDF files to SVG files
LICENSE=	gnu-gpl-v2

USE_TOOLS+=     gmake pkg-config
GNU_CONFIGURE=  yes

BUILD_TARGET=	pdf2svg

.include "../../print/poppler-glib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
