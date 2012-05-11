# $NetBSD: Makefile,v 1.1.1.1 2012/05/11 12:03:39 triaxx Exp $
#

DISTNAME=	Horde_Nls-1.1.6
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	http://pear.horde.org/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Translation-[0-9]*:../../wip/pear-Horde_Translation
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Util-[0-9]*:../../wip/pear-Horde_Util

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
