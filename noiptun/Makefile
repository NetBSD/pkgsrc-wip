# $NetBSD: Makefile,v 1.5 2005/07/27 16:26:42 thomasklausner Exp $
#

DISTNAME=		noiptun-1.0
WRKSRC=			${WRKDIR}/noiptun
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=noiptun/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://noiptun.sourceforge.net/
COMMENT=		Allows communication with computers that do not have an IP address

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		noiptun

.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
