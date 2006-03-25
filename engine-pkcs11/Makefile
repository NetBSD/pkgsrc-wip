# $NetBSD: Makefile,v 1.1.1.1 2006/03/25 02:53:56 udontknow Exp $
#

DISTNAME=		engine_pkcs11-0.1.3
PKGNAME=		engine-pkcs11-0.1.3
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/engine_pkcs11/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://www.opensc-project.org/engine_pkcs11/
COMMENT=	 	OpenSSL PKCS #11 engine for OpenSC

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../wip/libp11/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
