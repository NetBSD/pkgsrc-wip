# $NetBSD: Makefile,v 1.1.1.2 2003/10/29 17:27:46 poppnk Exp $
#

DISTNAME=	pnetlib-0.6.0.1
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	GNU Freedom for the Internet

DEPENDS=	pnet>=0.6.0:../../wip/pnet/

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_X11=	yes

.undef EXTRACT_USING_PAX # Tarball with GNU header
.include "../../mk/bsd.pkg.mk"
