# $NetBSD: Makefile,v 1.11 2008/08/06 13:52:33 yazzy Exp $
#

DISTNAME=	eet-1.0.1
CATEGORIES=	misc
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-05-19/ \
		http://www.ezunix.org/pkgsrc/e17/snapshots/2008-05-19/ \
		http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Distribution Container Library and Tools

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
