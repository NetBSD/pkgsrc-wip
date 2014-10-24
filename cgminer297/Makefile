# $Id: Makefile,v 1.1 2014/10/24 14:42:11 noud4 Exp $

DISTNAME=	cgminer-2.9.7
CATEGORIES=	finance
MASTER_SITES=	http://ck.kolivas.org/apps/cgminer/old/2.9/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://ck.kolivas.org/apps/cgminer/
COMMENT=	Bitcoin miner
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-cpumining
USE_TOOLS+=		pkg-config
USE_TOOLS+=		gmake
CFLAGS+=		-Dunix

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
