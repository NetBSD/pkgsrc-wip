# $NetBSD: Makefile,v 1.8 2012/10/07 17:41:39 asau Exp $
#

DISTNAME=	udhcp-0.9.8
CATEGORIES=	net
MASTER_SITES=	http://udhcp.busybox.net/source/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.busybox.net/
COMMENT=	Embedded DHCP Client/Server

PKG_DESTDIR_SUPPORT=	none

USE_TOOLS+=	gmake

ONLY_FOR_PlATFORM=	Linux-*-*

SUBST_CLASSES+= prefix
SUBST_STAGE.prefix=pre-build
SUBST_FILES.prefix=Makefile
SUBST_SED.prefix=\
	-e "s|prefix=|prefix=${PREFIX}\#|" \
	-e "s|SBINDIR=|SBINDIR=${PREFIX}/sbin \#|"

.include "../../mk/bsd.pkg.mk"
