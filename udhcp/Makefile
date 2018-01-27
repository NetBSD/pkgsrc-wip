# $NetBSD: Makefile,v 1.9 2012/11/25 23:32:31 othyro Exp $
#

DISTNAME=	udhcp-0.9.8
CATEGORIES=	net
MASTER_SITES=	http://udhcp.busybox.net/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.busybox.net/
COMMENT=	Embedded DHCP Client/Server


USE_TOOLS+=	gmake

ONLY_FOR_PlATFORM=	Linux-*-*

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-build
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=\
	-e "s|prefix=|prefix=${PREFIX}\#|" \
	-e "s|SBINDIR=|SBINDIR=${PREFIX}/sbin \#|"

.include "../../mk/bsd.pkg.mk"
