# $NetBSD: Makefile,v 1.2 2012/10/05 11:12:50 asau Exp $
#

DISTNAME=	Horde_Alarm-1.0.7
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	https://pear.horde.org/
COMMENT=	Interface dealing with alarms
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Date-[0-9]*:../../wip/pear-Horde_Date
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Exception-[0-9]*:../../wip/pear-Horde_Exception
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Translation-[0-9]*:../../wip/pear-Horde_Translation

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
