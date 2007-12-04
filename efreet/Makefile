# $NetBSD: Makefile,v 1.2 2007/12/04 04:17:23 netcap Exp $
#

DISTNAME=	efreet-0.0.3.006
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2007-08-26/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

DEPENDS+=       ecore>=0.9.9.041:../../wip/ecore
.include        "../../wip/ecore/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
