# $NetBSD: Makefile,v 1.3 2012/10/05 11:12:53 asau Exp $
#

DISTNAME=	Horde_Exception-1.0.9
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	https://pear.horde.org/
COMMENT=	Default exception handlers for Horde
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Translation-[0-9]*:../../wip/pear-Horde_Translation

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
