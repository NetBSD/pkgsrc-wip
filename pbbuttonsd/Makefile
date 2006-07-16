# $NetBSD: Makefile,v 1.2 2006/07/16 16:08:39 shattered Exp $
#

DISTNAME=		pbbuttonsd-0.7.2
CATEGORIES=		wip sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pbbuttons/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://pbbuttons.berlios.de/
COMMENT=		Daemon to handle laptop specific features

GNU_CONFIGURE=		YES
ONLY_FOR_PLATFORM=	Linux-*-*
USE_TOOLS+=		gmake
USE_LIBTOOL+=		YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
