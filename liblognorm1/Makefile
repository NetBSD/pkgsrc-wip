# $NetBSD: Makefile,v 1.1 2014/07/21 10:39:23 fhajny Exp $

DISTNAME=	liblognorm-1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.liblognorm.com/files/download/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.liblognorm.com/
COMMENT=	Tool to normalize log data
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	lognorm.pc.in

CONFIGURE_ARGS+=	--disable-docs

.include "../../textproc/json-c/buildlink3.mk"
.include "../../wip/libestr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
