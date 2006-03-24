# $NetBSD: Makefile,v 1.2 2006/03/24 21:51:19 udontknow Exp $
#

DISTNAME=		libp11-0.2.1
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/libp11/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://www.opensc-project.org/libp11/
COMMENT=		Convenience library for easy PKCS #11 implementation

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libp11.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
