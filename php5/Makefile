# $NetBSD: Makefile,v 1.1.1.1 2004/01/05 15:49:04 poppnk Exp $
#

PKGNAME=	php-${PHP5_VERSION}
CATEGORIES+=	lang

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.php.net/
COMMENT=	PHP Hypertext Preprocessor version 5

# Did conflicts works? xxx I think NO.
CONFLICTS+=	php-4 php-3
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
