# $NetBSD: Makefile,v 1.1.1.1 2004/12/15 00:22:34 poppnk Exp $
#

DISTNAME=		bridge-utils-1.0.4
CATEGORIES=		wip net linux
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bridge/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://bridge.sourceforge.net/
COMMENT=		Ethernet bridging utilities for GNU/Linux

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
