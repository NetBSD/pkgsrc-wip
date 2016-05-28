# $NetBSD: Makefile,v 1.5 2012/11/25 23:32:28 othyro Exp $
#

DISTNAME=		pbbuttonsd-0.7.2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pbbuttons/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pbbuttons.berlios.de/
COMMENT=		Daemon to handle laptop specific features


GNU_CONFIGURE=		YES
ONLY_FOR_PLATFORM=	Linux-*-*
USE_TOOLS+=		gmake
USE_LIBTOOL+=		YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
