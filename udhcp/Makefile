# $NetBSD: Makefile,v 1.6 2005/04/11 21:16:07 tvierling Exp $
#

DISTNAME=	udhcp-0.9.8
CATEGORIES=	net
MASTER_SITES=	http://udhcp.busybox.net/source/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.busybox.net/
COMMENT=	Embedded DHCP Client/Server

USE_GNU_TOOLS+=	make

ONLY_FOR_PlATFORM=	Linux-*-*

SUBST_CLASSES+= prefix
SUBST_STAGE.prefix=pre-build
SUBST_FILES.prefix=Makefile
SUBST_SED.prefix=\
	-e "s|prefix=|prefix=${PREFIX}\#|" \
	-e "s|SBINDIR=|SBINDIR=${PREFIX}/sbin \#|"

.include "../../mk/bsd.pkg.mk"
