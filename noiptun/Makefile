# $NetBSD: Makefile,v 1.6 2006/05/19 16:51:27 ykomatsu Exp $
#

DISTNAME=		noiptun-1.0
WRKSRC=			${WRKDIR}/noiptun
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=noiptun/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://noiptun.sourceforge.net/
COMMENT=		Allows communication with computers that do not have an IP address

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		noiptun

.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
