# $NetBSD: Makefile,v 1.2 2004/01/25 02:33:58 grantbeattie Exp $
#

DISTNAME=		xmmsctrl-1.6
CATEGORIES=		misc
MASTER_SITES=		http://www.docs.uu.se/~adavid/utils/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.docs.uu.se/~adavid/utils/
COMMENT=		Small utility to control xmms from the command line

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmmsctrl ${PREFIX}/bin/xmmsctrl

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
