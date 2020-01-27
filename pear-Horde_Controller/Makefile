# $NetBSD: Makefile,v 1.2 2012/10/05 11:12:51 asau Exp $
#

DISTNAME=	Horde_Controller-1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	https://pear.horde.org/
COMMENT=	Controller part of an MVC system for horde
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Exception-[0-9]*:../../wip/pear-Horde_Exception
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Injector-[0-9]*:../../wip/pear-Horde_Injector
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Log-[0-9]*:../../wip/pear-Horde_Log
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Support-[0-9]*:../../wip/pear-Horde_Support
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Util-[0-9]*:../../wip/pear-Horde_Util

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
