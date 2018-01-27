# $NetBSD: Makefile,v 1.2 2012/09/24 16:56:29 asau Exp $
#

DISTNAME=	acpi-1.5
PKGREVISION=	1
CATEGORIES=	linux sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=acpiclient/}

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://acpiclient.sourceforge.net/
COMMENT=	This is an acpi client for Linux

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
