# $NetBSD: Makefile,v 1.1.1.1 2012/05/11 13:13:59 triaxx Exp $
#

DISTNAME=	Horde_Cli-1.0.4
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	http://pear.horde.org/
COMMENT=	Command-line functionalities
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Support-[0-9]*:../../wip/pear-Horde_Support
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Horde_Translation-[0-9]*:../../wip/pear-Horde_Translation

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
