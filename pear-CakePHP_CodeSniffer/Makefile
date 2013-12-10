# $NetBSD: Makefile,v 1.2 2013/12/10 13:19:26 noud4 Exp $

DISTNAME=	CakePHP_CodeSniffer-0.1.18
CATEGORIES=	www
MASTER_SITES+=	http://pear.cakephp.org/get/

MAINTAINER=	noud4@home.nl
HOMEPAGE= 	http://pear.cakephp.org/
COMMENT=	CodeSniffer rules for checking code against the CakePHP coding standards
LICENSE=	mit

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-cakephp-[0-9]*:../../wip/pear-channel-cakephp
DEPENDS+=	${PHP_PKG_PREFIX}-pear-PHP_CodeSniffer>=1.4.4:../../wip/pear-PHP_CodeSniffer

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
