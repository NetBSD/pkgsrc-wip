# $NetBSD: Makefile,v 1.3 2004/01/11 23:22:07 poppnk Exp $
#

PKGNAME=	php-${PHP5_VERSION}
CATEGORIES+=	lang

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.php.net/
COMMENT=	PHP Hypertext Preprocessor version 5

CONFLICTS+=	php-[34]*
USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
