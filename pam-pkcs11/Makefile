# $NetBSD: Makefile,v 1.4 2006/05/01 14:20:08 shattered Exp $
#

DISTNAME=		pam_pkcs11-0.5.3
PKGNAME=		pam-pkcs11-0.5.3
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/pam_pkcs11/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://www.opensc-project.org/pam_pkcs11/
COMMENT=		PKCS #11 authentication method for PAM

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "options.mk"
PLIST_SRC+=		PLIST.common

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
