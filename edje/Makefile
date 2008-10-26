# $NetBSD: Makefile,v 1.24 2008/10/26 07:57:53 minskim Exp $
#

DISTNAME=	edje-0.9.9.043
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-05-19/ \
		http://www.ezunix.org/pkgsrc/e17/snapshots/2008-05-19/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

.include	"../../devel/eet/buildlink3.mk"
.include	"../../wip/ecore/buildlink3.mk"
.include	"../../wip/evas/buildlink3.mk"
.include	"../../lang/embryo/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
