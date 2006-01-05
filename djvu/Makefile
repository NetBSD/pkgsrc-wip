# $NetBSD: Makefile,v 1.4 2006/01/05 10:11:25 ghen Exp $

DISTNAME=	djvulibre-3.5.14
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=	oht@users.sourceforge.net
HOMEPAGE=   	http://djvulibre.djvuzone.org/
COMMENT=	Format and software platform for distributing documents and images

CONFIGURE_ARGS+=         --enable-djview

GNU_CONFIGURE=  YES

.include "../../x11/qt3-tools/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
