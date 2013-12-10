# $NetBSD: Makefile,v 1.2 2013/12/10 13:19:26 noud4 Exp $
#

DISTNAME=	fDOMDocument-1.4.2
CATEGORIES=	devel
MASTER_SITES+=	http://pear.netpirates.net/get/

MAINTAINER=	noud4@home.nl
HOMEPAGE= 	http://pear.netpirates.net/
COMMENT=	Extension to PHP\'s standard DOM to add methods and exceptions
LICENSE=	modified-bsd	# XXX unsure which bsd license

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-theseer-[0-9]*:../../wip/pear-channel-theseer
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
