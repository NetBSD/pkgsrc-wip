# $NetBSD: Makefile,v 1.3 2005/05/24 10:29:25 rillig Exp $
#

DISTNAME=		bridge-utils-1.0.4
CATEGORIES=		wip net linux
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bridge/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://bridge.sourceforge.net/
COMMENT=		Ethernet bridging utilities for GNU/Linux

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
