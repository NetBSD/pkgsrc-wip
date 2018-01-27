# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:10 noud4 Exp $

DISTNAME=	Swift-5.0.1
CATEGORIES=	mail
MASTER_SITES+=	http://pear.swiftmailer.org/get/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://swiftmailer.org/
COMMENT=	Free Feature-rich PHP Mailer
LICENSE=	gnu-lgpl-v3

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-swiftmailer-[0-9]*:../../wip/pear-channel-swiftmailer

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
