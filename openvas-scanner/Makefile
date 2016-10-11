# $NetBSD: Makefile,v 1.17 2016/09/19 13:04:27 wiz Exp $

DISTNAME=	openvas-libraries-8.0.8
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2351/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvas.org/
COMMENT=	Libraries for the Open Vulnerability Assessment System

USE_CMAKE=	YES
BUILD_DEFS+=	VARBASE
USE_LANGUAGES=	c++ c
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DLOCALSTATEDIR:PATH=${VARBASE}

# DragonFly-2.8.2 has dn_expand(3) in libc, and not have libresolv.
BUILDLINK_TRANSFORM.DragonFly+=	rm:-lresolv

.include "../../databases/hiredis/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
