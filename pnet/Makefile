# $NetBSD: Makefile,v 1.1.1.2 2003/10/29 15:52:26 poppnk Exp $
#

DISTNAME=	pnet-0.6.0
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	GNU Freedom for the Internet

# XXX wip dirs must be patched when uploading to official pkgsrc XXX #
DEPENDS+=	treecc>=0.2.6:../../wip/treecc/
#DEPENDS+=	pnetlib>=0.6.0:../../wip/pnetlib/

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

#.include "../../wip/pnetlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
