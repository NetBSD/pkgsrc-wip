# $NetBSD: Makefile,v 1.26 2008/11/19 01:16:51 jsonn Exp $
#

DISTNAME=	edje-0.9.9.050
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-09-25/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

.include	"../../devel/eet/buildlink3.mk"
.include	"../../wip/ecore/buildlink3.mk"
.include	"../../wip/evas/buildlink3.mk"
.include	"../../lang/embryo/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
