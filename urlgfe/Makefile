# $NetBSD: Makefile,v 1.6 2007/07/08 19:14:41 minskim Exp $
#

DISTNAME=		urlgfe-1.0.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=urlget/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://urlget.sourceforge.net/
COMMENT=		Download manager for X

USE_DIRS+=		xdg-1.4
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
