# $NetBSD: Makefile,v 1.1.1.1 2003/09/01 12:54:06 adrian_p Exp $

DISTNAME=	HTML_Select-1.2
PKGNAME=	pear-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PAIR_PACKAGE}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://pear.php.net/package/HTML_Common
COMMENT=	HTML_Select is a class for generating HTML form select elements

DEPENDS+=	pear-HTML_Common>=1.1:../../wip/pear-HTML_Common

USE_BUILDLINK2=		YES

.include "../../wip/php4/package.mk"
.include "../../mk/bsd.pkg.mk"
