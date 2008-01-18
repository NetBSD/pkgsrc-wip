# $NetBSD: Makefile,v 1.7 2008/01/18 04:30:16 tnn2 Exp $

DISTNAME=	opensc-0.10.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/opensc/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=	http://www.opensc-project.org/openct/
COMMENT=		Smart Card Reader drivers and middleware

GNU_CONFIGURE=	YES
USE_LIBTOOL=		YES
USE_OLD_DES_API=	YES
USE_TOOLS+=	gmake pkg-config
USE_BUILTIN.openssl=	NO

.include "options.mk"

USE_OLD_DES_API=	YES
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-sensitive-logging

.include "../../devel/libltdl/buildlink3.mk"
.include "../../wip/openct/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
