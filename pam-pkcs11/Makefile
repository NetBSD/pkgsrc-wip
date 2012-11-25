# $NetBSD: Makefile,v 1.8 2012/11/25 23:08:44 lexort Exp $

DISTNAME=		pam_pkcs11-0.5.3
PKGNAME=		pam-pkcs11-0.5.3
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/pam_pkcs11/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://www.opensc-project.org/pam_pkcs11/
COMMENT=		PKCS \#11 authentication method for PAM
LICENSE=		gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.include "options.mk"
PLIST_SRC+=		PLIST.common

# After updating, send a bashism bug report upstream.
USE_TOOLS+=		bash
REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${PREFIX}/bin/bash
REPLACE_FILES.bash=	tools/make_hash_link.sh

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
