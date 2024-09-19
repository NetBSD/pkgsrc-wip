# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:09 othyro Exp $
#

DISTNAME=		bridge-utils-1.0.4
CATEGORIES=		net linux
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bridge/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.linuxfoundation.org/collaborate/workgroups/networking/bridge
COMMENT=		Ethernet bridging utilities for GNU/Linux
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
