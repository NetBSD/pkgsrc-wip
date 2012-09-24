# $NetBSD: Makefile,v 1.6 2012/09/24 17:14:39 asau Exp $
#

DISTNAME=		bridge-utils-1.0.4
CATEGORIES=		net linux
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bridge/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.linuxfoundation.org/collaborate/workgroups/networking/bridge
COMMENT=		Ethernet bridging utilities for GNU/Linux
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
