# $NetBSD: Makefile,v 1.6 2012/10/01 21:43:24 asau Exp $
#

DISTNAME=		jpgtn-2.06
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jpgtn/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jpgtn.sourceforge.net/
COMMENT=		Thumbnail generator for JPEG images

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
