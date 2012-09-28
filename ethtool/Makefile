# $NetBSD: Makefile,v 1.4 2012/09/28 22:07:35 asau Exp $
#

DISTNAME=		ethtool-1.6
CATEGORIES=		net linux
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gkernel/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://gkernel.sourceforge.net/
COMMENT=		Display or change ethernet card settings

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
