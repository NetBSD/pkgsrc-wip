# $NetBSD: Makefile,v 1.6 2008/02/21 23:56:48 shindenmorr Exp $
#

DISTNAME=	efreet-0.0.3.042
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
