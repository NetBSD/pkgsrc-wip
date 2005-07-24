# $NetBSD: Makefile,v 1.3 2005/07/24 20:46:23 cetrox Exp $
#

DISTNAME=		urlgfe-0.98
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=urlget/}

MAINTAINER=		ccatrian@eml.cc
HOMEPAGE=		http://urlget.sourceforge.net/
COMMENT=		Download manager for X

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
