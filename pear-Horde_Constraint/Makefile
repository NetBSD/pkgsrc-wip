# $NetBSD: Makefile,v 1.1.1.1 2012/05/11 13:49:58 triaxx Exp $
#

DISTNAME=	Horde_Constraint-1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	http://pear.horde.org/
COMMENT=	Constraints builder for horde
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
