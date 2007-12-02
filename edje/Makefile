# $NetBSD: Makefile,v 1.12 2007/12/02 14:50:13 hoka_adam Exp $
#

DISTNAME=	edje-0.5.0.041
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2007-08-26/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS=	pkg-config
DEPENDS+=	ecore>=0.9.9.041:../../wip/ecore
DEPENDS+=	embryo>=0.9.1.041:../../wip/embryo
.include	"../../wip/ecore/buildlink3.mk"
.include	"../../wip/embryo/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
