# $NetBSD: Makefile,v 1.10 2010/01/17 12:03:29 thomasklausner Exp $
#

DISTNAME=		noiptun-1.0
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=noiptun/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://noiptun.sourceforge.net/
COMMENT=		Allows communication with computers that do not have an IP address

WRKSRC=			${WRKDIR}/noiptun

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		noiptun

SUBST_CLASSES+=		net
SUBST_STAGE.net=	pre-configure
SUBST_FILES.net=	configure Makefile.in
SUBST_SED.net=		-e 's/libnet-config/libnet11-config/'
SUBST_MESSAGE.net=	Fix libnet-config name.

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
