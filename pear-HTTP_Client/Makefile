# $NetBSD: Makefile,v 1.1.1.1 2006/12/06 01:41:39 othyro Exp $

DISTNAME=	HTTP_Client-1.1.0
CATEGORIES+=	www

MAINTAINER=	othyro@freeshell.org
COMMENT=	A simple HTTP client class in PHP

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_URL>=1.0.12:../../net/pear-Net_URL
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.2:../../net/pear-Net_Socket
DEPENDS+=	${PHP_PKG_PREFIX}-pear-HTTP_Request>=1.2.3:../../www/pear-HTTP_Request

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
