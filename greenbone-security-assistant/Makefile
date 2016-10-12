# $NetBSD: Makefile,v 1.17 2016/09/19 13:04:27 wiz Exp $

DISTNAME=	greenbone-security-assistant-6.0.11
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2363/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvas.org/
COMMENT=	Manager for OpenVAS
LICENSE=	gnu-gpl-v2

USE_CMAKE=	YES
BUILD_DEFS+=	VARBASE
USE_LANGUAGES=	c++ c
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DLOCALSTATEDIR:PATH=${VARBASE}

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../wip/openvas-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
