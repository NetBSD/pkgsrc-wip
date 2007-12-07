# $NetBSD: Makefile,v 1.1 2007/12/07 20:37:39 briandealwis Exp $
#

DISTNAME=	pdf2svg-0.2
CATEGORIES=	converters
MASTER_SITES=	http://www.cityinthesky.co.uk/files/

MAINTAINER=	bsd@cs.ubc.ca
HOMEPAGE=	http://www.cityinthesky.co.uk/files/
COMMENT=	Small utility to convert PDF files to SVG files
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

BUILD_TARGET=	pdf2svg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdf2svg ${PREFIX}/bin/pdf2svg

.include "../../print/poppler-glib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
