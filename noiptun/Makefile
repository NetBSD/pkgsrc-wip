# $NetBSD: Makefile,v 1.1.1.1 2004/01/01 22:38:26 mpasternak Exp $
#

DISTNAME=		noiptun-1.0
WRKSRC=			${WRKDIR}/noiptun
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=noiptun/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://noiptun.sourceforge.net/
COMMENT=		Allows communication with computers that do not have an IP address

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
ALL_TARGET=		noiptun

.include "../../devel/libnet/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
