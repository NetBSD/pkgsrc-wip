# $NetBSD: Makefile,v 1.13 2007/12/02 14:50:13 hoka_adam Exp $
#

DISTNAME=	evas-0.9.9.041
PKGREVISISON=	1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2007-08-26/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightened Canvas Library

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS=	pkg-config
DEPENDS+=	eet>=0.9.10.041:../../wip/eet
DEPENDS+=	librsvg>=2.16.1:../../graphics/librsvg
DEPENDS+=	libungif>=4.1.4:../../graphics/libungif
DEPENDS+=	freetype2>=2.3.4:../../graphics/freetype2
.include	"../../wip/eet/buildlink3.mk"
.include	"../../databases/edb/buildlink3.mk"
.include	"../../graphics/librsvg/buildlink3.mk"
.include	"../../graphics/libungif/buildlink3.mk"
.include	"../../graphics/freetype2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
