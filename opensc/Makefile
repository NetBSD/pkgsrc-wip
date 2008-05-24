# $NetBSD: Makefile,v 1.9 2008/05/24 15:34:13 tnn2 Exp $

DISTNAME=		opensc-0.11.4
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/opensc/

MAINTAINER=		hasso@estpak.ee
HOMEPAGE=		http://www.opensc-project.org/openct/
COMMENT=		Smart Card drivers and middleware

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_OLD_DES_API=	YES
USE_TOOLS+=		gmake pkg-config
USE_BUILTIN.openssl=	NO
PLIST_SRC+=		${PKGDIR}/PLIST.common

.include "options.mk"

USE_OLD_DES_API=	YES
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-sensitive-logging

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
