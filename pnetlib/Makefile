# $NetBSD: Makefile,v 1.1.1.1 2003/07/18 16:46:01 poppnk Exp $
#

DISTNAME=	pnetlib-0.5.8
CATEGORIES=	lang
MASTER_SITES=	http://ftp.gnu.org/gnu/dotgnu/pnet/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	GNU Freedom for the Internet

DEPENDS+=	pnet>=0.5.8:../../wip/pnet

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
