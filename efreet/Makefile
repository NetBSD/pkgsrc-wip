# $NetBSD: Makefile,v 1.14 2009/07/14 22:25:45 jsonn Exp $
#

DISTNAME=	efreet-0.5.0.061
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-06-14/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	pkg-config

.include "../../wip/ecore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
