# $NetBSD: Makefile,v 1.2 2004/01/25 02:23:09 grantbeattie Exp $
#

DISTNAME=		hasciicam-0.9
CATEGORIES=		graphics net
MASTER_SITES=		http://ascii.dyne.org/ \
			http://www.autistici.org/dyne/hasciicam/ \
			http://freesoftware.fsf.org/download/hasciicam/

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://ascii.dyne.org/
COMMENT=		Live ascii video on the web

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../graphics/aalib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
