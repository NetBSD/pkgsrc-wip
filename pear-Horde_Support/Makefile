# $NetBSD: Makefile,v 1.3 2012/10/05 11:12:55 asau Exp $
#

DISTNAME=	Horde_Support-1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	https://pear.horde.org/
COMMENT=	Support classes
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Exception-[0-9]*:../../wip/pear-Horde_Exception
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Stream_Wrapper-[0-9]*:../../wip/pear-Horde_Stream_Wrapper

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
