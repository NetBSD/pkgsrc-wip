# $NetBSD: Makefile,v 1.3 2004/05/02 21:34:47 blef Exp $
#

DISTNAME=		hasciicam-0.9
CATEGORIES=		graphics net
MASTER_SITES=		http://ascii.dyne.org/ \
			http://www.autistici.org/dyne/hasciicam/ \
			http://freesoftware.fsf.org/download/hasciicam/

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://ascii.dyne.org/
COMMENT=		Live ascii video on the web

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../graphics/aalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
