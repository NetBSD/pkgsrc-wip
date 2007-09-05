# $NetBSD: Makefile,v 1.1.1.1 2007/09/05 13:19:31 emil_s Exp $
#

DISTNAME=	jp2a-1.0.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jp2a/}

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://jp2a.sourceforge.net/
COMMENT=	JPEG to ASCII converter

GNU_CONFIGURE=	yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
