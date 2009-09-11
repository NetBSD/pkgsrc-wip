# $NetBSD: Makefile,v 1.30 2009/09/11 22:15:22 jsonn Exp $
#

DISTNAME=	edje-0.9.92.062
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-07-29/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	pkg-config

REPLACE_PYTHON+=	utils/inkscape2edc
.include	"../../lang/python/application.mk"

.include	"../../devel/eet/buildlink3.mk"
.include	"../../graphics/evas/buildlink3.mk"
.include	"../../lang/embryo/buildlink3.mk"
.include	"../../wip/ecore/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
