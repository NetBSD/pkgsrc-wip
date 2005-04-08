# $NetBSD: Makefile,v 1.2 2005/04/08 17:31:51 peterih Exp $
#

DISTNAME=		vnc2swf-0.4.2
CATEGORIES=		wip
MASTER_SITES=		http://www.unixuser.org/~euske/vnc2swf/

MAINTAINER=		pih@xbase.dk
HOMEPAGE=		http://www.unixuser.org/~euske/vnc2swf/
COMMENT=		Record vnc session as flash movie

DEPENDS+=               ming>=0.2:../../wip/ming

USE_BUILDLINK3=		yes
#USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_X11=                yes

.include "../../wip/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
