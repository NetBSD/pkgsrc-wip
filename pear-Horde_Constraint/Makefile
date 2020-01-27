# $NetBSD: Makefile,v 1.2 2012/10/05 11:12:51 asau Exp $
#

DISTNAME=	Horde_Constraint-1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://pear.horde.org/get/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	https://pear.horde.org/
COMMENT=	Constraints builder for horde
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-horde-[0-9]*:../../wip/pear-channel-horde

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
