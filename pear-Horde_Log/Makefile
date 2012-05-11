# $NetBSD: Makefile,v 1.1.1.1 2012/05/11 13:55:30 triaxx Exp $
#

DISTNAME=	Horde_Log-1.1.2
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	http://pear.horde.org/
COMMENT=	Logging package for horde
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Exception-[0-9]*:../../wip/pear-Horde_Exception
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Support-[0-9]*:../../wip/pear-Horde_Support

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
