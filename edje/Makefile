# $NetBSD: Makefile,v 1.13 2007/12/04 04:17:23 netcap Exp $
#

DISTNAME=	edje-0.5.0.041
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2007-08-26/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

.include	"../../wip/ecore/buildlink3.mk"
.include	"../../wip/embryo/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
