# $NetBSD: Makefile,v 1.5 2005/04/11 21:13:00 tvierling Exp $
#

DISTNAME=		hasciicam-0.9
CATEGORIES=		graphics net
MASTER_SITES=		http://ascii.dyne.org/ \
			http://www.autistici.org/dyne/hasciicam/ \
			http://freesoftware.fsf.org/download/hasciicam/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ascii.dyne.org/
COMMENT=		Live ascii video on the web

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../graphics/aalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
