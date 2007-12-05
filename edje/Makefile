# $NetBSD: Makefile,v 1.15 2007/12/05 06:29:49 netcap Exp $
#

DISTNAME=	edje-0.5.0.041
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=   http://www.yazzy.org/pkgsrc/e17/ \
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
