# $NetBSD: Makefile,v 1.13 2009/06/07 21:27:19 jsonn Exp $
#

DISTNAME=	efreet-0.5.0.060
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-04-22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

.include "../../wip/ecore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
