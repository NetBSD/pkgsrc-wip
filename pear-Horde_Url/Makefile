# $NetBSD: Makefile,v 1.3 2012/10/05 11:12:55 asau Exp $
#

DISTNAME=	Horde_Url-1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	https://pear.horde.org/
COMMENT=	URL manipulation class
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Exception-[0-9]*:../../wip/pear-Horde_Exception

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
