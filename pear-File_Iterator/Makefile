# $NetBSD: Makefile,v 1.1 2013/07/14 12:21:30 noud4 Exp $

DISTNAME=	File_Iterator-1.3.3
CATEGORIES=	devel
MASTER_SITES+=	http://pear.phpunit.de/get/

MAINTAINER=	noud4@home.nl
HOMEPAGE= 	http://pear.phpunit.de/
COMMENT=	Filters files based on a list of suffixes
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-phpunit-[0-9]*:../../wip/pear-channel-phpunit

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
