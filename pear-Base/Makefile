# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:09 noud4 Exp $

DISTNAME=	Base-1.8
CATEGORIES=	devel
MASTER_SITES+=	http://components.ez.no/get/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://www.ezcomponents.org/docs/tutorials/Base
COMMENT=	Basic functionality that all eZ Components need
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-ezc-[0-9]*:../../wip/pear-channel-ezc

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
