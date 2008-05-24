# $NetBSD: Makefile,v 1.19 2008/05/24 15:34:09 tnn2 Exp $
#

DISTNAME=	edje-0.5.0.042
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-01-25/ \
		http://www.yazzy.org/pkgsrc/e17/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

.include	"../../wip/eet/buildlink3.mk"
.include	"../../wip/ecore/buildlink3.mk"
.include	"../../wip/evas/buildlink3.mk"
.include	"../../wip/embryo/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
