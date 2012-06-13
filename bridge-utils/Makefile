# $NetBSD: Makefile,v 1.5 2012/06/13 19:52:22 othyro Exp $
#

DISTNAME=		bridge-utils-1.0.4
CATEGORIES=		net linux
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bridge/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.linuxfoundation.org/collaborate/workgroups/networking/bridge
COMMENT=		Ethernet bridging utilities for GNU/Linux
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
