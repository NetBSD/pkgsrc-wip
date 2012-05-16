# $NetBSD: Makefile,v 1.1.1.1 2012/05/16 07:02:18 triaxx Exp $
#

DISTNAME=	Horde_History-1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	http://pear.horde.org/
COMMENT=	Change tracker in horde
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Db-[0-9]*:../../wip/pear-Horde_Db
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Exception-[0-9]*:../../wip/pear-Horde_Exception

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
