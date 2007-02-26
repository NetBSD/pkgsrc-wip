# $NetBSD: Makefile,v 1.1.1.1 2007/02/26 18:54:19 dzoe Exp $
#

DISTNAME=		courierpassd-1.1.2
CATEGORIES=		security
MASTER_SITES=		http://www.arda.homeunix.net/store/

MAINTAINER=		joe@joe.cz
HOMEPAGE=		http://www.arda.homeunix.net/store/
COMMENT=		Password changing daemon using courier-authlib

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes


.include "../../security/courier-authlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
