# $NetBSD: Makefile,v 1.11 2015/01/13 05:25:02 obache Exp $
#

DISTNAME=		wireless_tools.27
PKGNAME=		${DISTNAME:S/./-/:S/_/-/}
CATEGORIES=		net linux
MASTER_SITES=		http://www.hpl.hp.com/personal/Jean_Tourrilhes/Linux/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hpl.hp.com/personal/Jean_Tourrilhes/Linux/Tools.html
COMMENT=		Tools for manipulating Linux Wireless Extensions
LICENSE=		gnu-gpl-v2


ONLY_FOR_PLATFORM=	Linux-*-*
USE_TOOLS+=		gmake

.include "../../mk/bsd.pkg.mk"
