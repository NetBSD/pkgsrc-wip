# $NetBSD: Makefile,v 1.1.1.1 2008/04/25 11:11:31 marttikuparinen Exp $
#

DISTNAME=	mod_authnz_external-${DISTVERS}
#PKGREVISION=	1
PKGNAME=	${APACHE_PKG_PREFIX}-authnz-external-${DISTVERS}
CATEGORIES=	www
MASTER_SITES=	http://unixpapa.com/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unixpapa.com/mod_authnz_external/
COMMENT=	Apache module for external program authentication

PKG_APACHE_ACCEPTED=	apache22

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_authnz_external.${MODULE_EXT}

DISTVERS=	3.1.0
MODULE_EXT=	la
MESSAGE_SUBST+=	MODULE_NAME=authnz_external_module

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
