# $NetBSD: Makefile,v 1.1.1.1 2003/08/29 11:18:24 adrian_p Exp $
#

DISTNAME=	mod_security-1.6
PKGNAME=	${DISTNAME:S/mod_/ap-/}
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/download/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://www.modsecurity.org/
COMMENT=	Intrusion detection and prevention engine for web applications

USE_BUILDLINK2=		yes
APACHE_MODULE=		yes

APACHE_MODULE_NAME=	${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRC=      ${DISTNAME:C|-.*||}.c
APACHE_MODULE_SRCDIR=	${WRKSRC}/apache1

.include "../../www/apache/buildlink2.mk"
.include "../../www/apache/module.mk"

.include "../../mk/bsd.pkg.mk"
