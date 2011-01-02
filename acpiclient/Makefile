# $NetBSD: Makefile,v 1.1.1.1 2011/01/02 16:38:53 rubengonzalez Exp $
#

DISTNAME=	acpi-1.5
PKGREVISION=	1
CATEGORIES=	linux sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=acpiclient/}

MAINTAINER=	rga@sdf.lonestar.org
HOMEPAGE=	http://acpiclient.sourceforge.net/
COMMENT=	This is an acpi client for Linux

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=     gmake

ONLY_FOR_PLATFORM= Linux-*-*

.include "../../mk/bsd.pkg.mk"
