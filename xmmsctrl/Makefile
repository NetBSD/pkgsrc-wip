# $NetBSD: Makefile,v 1.1.1.1 2003/09/21 20:41:05 mpasternak Exp $
#

DISTNAME=		xmmsctrl-1.6
CATEGORIES=		misc
MASTER_SITES=		http://www.docs.uu.se/~adavid/utils/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.docs.uu.se/~adavid/utils/
COMMENT=		Small utility to control xmms from the command line

USE_BUILDLINK2=		YES
USE_GMAKE=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmmsctrl ${PREFIX}/bin/xmmsctrl

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
