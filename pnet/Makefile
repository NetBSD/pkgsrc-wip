# $NetBSD: Makefile,v 1.1.1.1 2003/07/18 16:46:49 poppnk Exp $
#

DISTNAME=	pnet-0.5.8
CATEGORIES=	lang
MASTER_SITES=	http://ftp.gnu.org/gnu/dotgnu/pnet/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	GNU Freedom for the Internet

# XXX wip dirs must be patched when uploading to official pkgsrc XXX #
DEPENDS+=	treecc>=0.2.4:../../wip/treecc/
DEPENDS+=	pnetlib>=0.5.8:../../wip/pnetlib/

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

.include "../../mk/bsd.pkg.mk"
