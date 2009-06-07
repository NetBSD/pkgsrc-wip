# $NetBSD: Makefile,v 1.29 2009/06/07 21:27:03 jsonn Exp $
#

DISTNAME=	edje-0.9.92.060
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-04-22/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

REPLACE_PYTHON+=	utils/inkscape2edc
.include	"../../lang/python/application.mk"

.include	"../../devel/eet/buildlink3.mk"
.include	"../../wip/ecore/buildlink3.mk"
.include	"../../graphics/evas/buildlink3.mk"
.include	"../../lang/embryo/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
