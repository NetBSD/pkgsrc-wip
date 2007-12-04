# $NetBSD: Makefile,v 1.14 2007/12/04 04:17:23 netcap Exp $
#

DISTNAME=	evas-0.9.9.041
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2007-08-26/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightened Canvas Library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

.include	"../../wip/eet/buildlink3.mk"
.include	"../../databases/edb/buildlink3.mk"
.include	"../../graphics/librsvg/buildlink3.mk"
.include	"../../graphics/libungif/buildlink3.mk"
.include	"../../graphics/freetype2/buildlink3.mk"
.include	"../../graphics/png/buildlink3.mk"
.include	"../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
