# $NetBSD$

DISTNAME=	hiawatha-11.5
CATEGORIES=	www
MASTER_SITES=	https://www.hiawatha-webserver.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.hiawatha-webserver.org/files/
COMMENT=	Advanced and secure webserver for Unix
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes

#DEPENDS+=	php-[0-9]*:../../lang/php

REPLACE_PHP+=	extra/letsencrypt/lefh.in

.include "../../lang/php/replace.mk"
.include "../../lang/php83/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
