# $NetBSD: Makefile,v 1.7 2008/03/06 14:54:08 thomasklausner Exp $
#

DISTNAME=	efreet-0.0.3.042
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=   http://download.enlightenment.org/snapshots/2008-01-25/ \
		http://www.yazzy.org/pkgsrc/e17/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

.include "../../wip/ecore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
