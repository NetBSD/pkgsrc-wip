# $NetBSD: Makefile,v 1.1 2013/07/14 11:35:35 noud4 Exp $

DISTNAME=	ConsoleTools-1.6.1
CATEGORIES=	devel
MASTER_SITES+=	http://components.ez.no/get/

MAINTAINER=	noud4@home.nl
HOMEPAGE= 	http://www.ezcomponents.org/docs/tutorials/ConsoleTools
COMMENT=	Tools to build applications that run on a computer console
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-ezc-[0-9]*:../../wip/pear-channel-ezc
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Base>=1.8:../../wip/pear-Base

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
