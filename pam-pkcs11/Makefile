# $NetBSD: Makefile,v 1.1.1.1 2005/11/24 13:42:36 udontknow Exp $
#

DISTNAME=		pam_pkcs11-0.5.3
PKGNAME=		pam-pkcs11-0.5.3
CATEGORIES=		security
MASTER_SITES=		http://www.opensc.org/files/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://www.opensc.org/pam_pkcs11/
COMMENT=		PKCS #11 authentication method for PAM

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		YES

.include "options.mk"
PLIST_SRC+=		PLIST.common

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
