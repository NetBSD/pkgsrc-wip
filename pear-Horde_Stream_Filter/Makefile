# $NetBSD: Makefile,v 1.1.1.1 2012/05/11 14:16:29 triaxx Exp $
#

DISTNAME=	Horde_Stream_Filter-1.1.0
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	http://pear.horde.org/
COMMENT=	Stream filters for horde
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
