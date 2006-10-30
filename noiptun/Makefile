# $NetBSD: Makefile,v 1.7 2006/10/30 22:45:31 shattered Exp $
#

DISTNAME=		noiptun-1.0
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=noiptun/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://noiptun.sourceforge.net/
COMMENT=		Allows communication with computers that do not have an IP address

WRKSRC=			${WRKDIR}/noiptun

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		noiptun

.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
