# $NetBSD: Makefile,v 1.2 2012/09/24 18:26:55 asau Exp $
#

DISTNAME=		courierpassd-1.1.2
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.arda.homeunix.net/store/
LICENSE=		gnu-gpl-v2

MAINTAINER=		joe@joe.cz
HOMEPAGE=		http://www.arda.homeunix.net/store/
COMMENT=		Password changing daemon using courier-authlib


USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes


.include "../../security/courier-authlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
