# $NetBSD: Makefile,v 1.17 2016/09/19 13:04:27 wiz Exp $

DISTNAME=	openvas-cli-1.4.4
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2332/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openvas.org/
COMMENT=	Commandline Interface for OpenVAS
LICENSE=	gnu-gpl-v2

USE_CMAKE=	YES
BUILD_DEFS+=	VARBASE
USE_LANGUAGES=	c++ c
USE_TOOLS+=	pkg-config bash

CMAKE_CONFIGURE_ARGS+=	-DLOCALSTATEDIR:PATH=${VARBASE}

BUILDLINK_TRANSFORM+=	rm:-Werror # -Wmissing-field-initializers

REPLACE_BASH+=	dialog/omp-dialog

.include "../../wip/openvas-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
