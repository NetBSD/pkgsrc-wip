# $NetBSD: Makefile,v 1.1.1.1 2012/05/11 13:01:19 triaxx Exp $
#

DISTNAME=	Horde_Browser-1.0.6
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	http://pear.horde.org/
COMMENT=	Browser informations
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Exception-[0-9]*:../../wip/pear-Horde_Exception
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Util-[0-9]*:../../wip/pear-Horde_Util

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
