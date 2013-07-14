# $NetBSD: Makefile,v 1.1 2013/07/14 12:43:02 noud4 Exp $
#

DISTNAME=	phploc-1.7.4
CATEGORIES=	devel
MASTER_SITES+=	http://pear.phpunit.de/get/

MAINTAINER=	noud4@home.nl
HOMEPAGE= 	http://pear.phpunit.de
COMMENT=	A tool for quickly measuring the size of a project

DEPENDS+=	${PHP_PKG_PREFIX}-pear-ConsoleTools>=1.5.1:../../wip/pear-ConsoleTools
DEPENDS+=	${PHP_PKG_PREFIX}-pear-FinderFacade>=1.0.5:../../wip/pear-Finder

# XXX option bytekit

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
