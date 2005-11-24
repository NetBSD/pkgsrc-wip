# $NetBSD: Makefile,v 1.1.1.1 2005/11/24 03:55:22 udontknow Exp $
#

DISTNAME=		libp11-0.2.1
CATEGORIES=		security
MASTER_SITES=		http://www.opensc.org/files/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://www.opensc.org/libp11/
COMMENT=		Convenience library for easy PKCS #11 implementation

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libp11.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
