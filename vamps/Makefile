# $NetBSD: Makefile,v 1.2 2009/12/04 13:16:19 rhialto Exp $

DISTNAME=		vamps-0.99.2
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vamps/}

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		http://vamps.sourceforge.net/
COMMENT=		Requantizer for shrinking DVDs

USE_TOOLS+=		gmake
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
