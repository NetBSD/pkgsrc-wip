# $NetBSD: Makefile,v 1.4 2012/10/05 11:12:49 asau Exp $
#

DISTNAME=	HTTP_Request2-2.1.1
CATEGORIES=	www
MASTER_SITES=	http://download.pear.php.net/package/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.pear.php.net/package/
COMMENT=	Provides an easy way to perform HTTP requests
LICENSE=	2-clause-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_URL2>=0.2.0:../../wip/pear-Net_URL2

USE_LANGUAGES=	# none

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
