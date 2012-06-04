# $NetBSD: Makefile,v 1.3 2012/06/04 00:05:10 othyro Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
