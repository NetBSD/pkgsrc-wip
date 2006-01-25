# $NetBSD: Makefile,v 1.1.1.1 2006/01/25 11:13:30 poppnk Exp $
#

DISTNAME=		pbbuttonsd-0.7.2
CATEGORIES=		wip sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pbbuttons/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://pbbuttons.sf.net/
COMMENT=		Daemon to handle laptop specific features

GNU_CONFIGURE=		YES
ONLY_FOR_PLATFORM=	Linux-*-*
USE_TOOLS+=		gmake
USE_LIBTOOL+=		YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
