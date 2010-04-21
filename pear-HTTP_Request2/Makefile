# $NetBSD: Makefile,v 1.2 2010/04/21 14:51:42 uccwen Exp $
#

DISTNAME=	HTTP_Request2-0.5.2
CATEGORIES=	www
MASTER_SITES=	http://download.pear.php.net/package/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.pear.php.net/package/
COMMENT=	Provides an easy way to perform HTTP requests
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_URL2>=0.2.0:../../wip/pear-Net_URL2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
