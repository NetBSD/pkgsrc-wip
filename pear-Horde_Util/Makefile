# $NetBSD: Makefile,v 1.2 2012/10/05 11:12:55 asau Exp $
#

DISTNAME=	Horde_Util-1.3.0
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	https://pear.horde.org/
COMMENT=	Useful functionalities for horde
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Url-[0-9]*:../../wip/pear-Horde_Url

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
