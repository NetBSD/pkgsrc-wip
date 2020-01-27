# $NetBSD: Makefile,v 1.2 2012/10/05 11:12:53 asau Exp $
#

DISTNAME=	Horde_Data-1.0.7
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	https://pear.horde.org/
COMMENT=	Data import and export backends for horde
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Browser-[0-9]*:../../wip/pear-Horde_Browser
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Exception-[0-9]*:../../wip/pear-Horde_Exception
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Icalendar-[0-9]*:../../wip/pear-Horde_Icalendar
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Mime-[0-9]*:../../wip/pear-Horde_Mime
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Translation-[0-9]*:../../wip/pear-Horde_Translation
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Util-[0-9]*:../../wip/pear-Horde_Util

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
