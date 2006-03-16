# $NetBSD: Makefile,v 1.1.1.1 2006/03/16 09:05:16 bartoszkuzma Exp $
#

DISTNAME=		granule-1.2.0
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=granule/}

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://granule.sourceforge.net/
COMMENT=		Program for Leitner methodology for learning new words

USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/libassa/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
