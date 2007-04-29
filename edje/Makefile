# $NetBSD: Makefile,v 1.9 2007/04/29 13:12:22 grzela1 Exp $
#

DISTNAME=	edje-0.5.0.037
CATEGORIES=	graphics
MASTER_SITES=	http://enlightenment.freedesktop.org/files/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	grzela@seculture.com
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS=	pkg-config
DEPENDS+=	ecore>=0.9.9.037:../../wip/ecore
DEPENDS+=	embryo>=0.9.1.037:../../wip/embryo
.include	"../../wip/ecore/buildlink3.mk"
.include	"../../wip/embryo/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
