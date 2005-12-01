# $NetBSD: Makefile,v 1.2 2005/12/01 03:51:36 minskim Exp $
#

DISTNAME=		clex-3.14
CATEGORIES=		sysutils
MASTER_SITES=		http://www.clex.sk/download/

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://www.clex.sk/download/
COMMENT=		File manager with a full-screen user interface

USE_NCURSES=		# enter_{bold,reverse,underline}_mode
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
