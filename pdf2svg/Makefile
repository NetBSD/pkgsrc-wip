# $NetBSD: Makefile,v 1.3 2010/01/18 09:38:28 thomasklausner Exp $
#

DISTNAME=	pdf2svg-0.2.1
PKGREVISION=	1
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
