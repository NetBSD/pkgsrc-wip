# $NetBSD: Makefile,v 1.17 2016/09/19 13:04:27 wiz Exp $

DISTNAME=	openvas-scanner-5.0.7
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2367/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvas.org/
COMMENT=	Open Vulnerability Assessment System Scanner
LICENSE=	gnu-gpl-v2

USE_CMAKE=	YES
BUILD_DEFS+=	VARBASE
USE_LANGUAGES=	c++ c
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DLOCALSTATEDIR:PATH=${VARBASE}

.include "../../wip/openvas-libraries/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
