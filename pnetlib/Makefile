# $NetBSD: Makefile,v 1.2 2004/01/04 02:07:02 poppnk Exp $
#

DISTNAME=	pnetlib-0.6.2
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	GNU Freedom for the Internet

DEPENDS=	pnet>=0.6.2:../../wip/pnet/

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
# Strange...X or not X is automatically detected by configure :/
#USE_X11=	yes

.undef EXTRACT_USING_PAX # Tarball with GNU header
.include "../../mk/bsd.pkg.mk"
