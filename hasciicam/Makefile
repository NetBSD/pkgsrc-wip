# $NetBSD: Makefile,v 1.1.1.1 2003/06/03 14:30:19 poppnk Exp $
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
USE_GMAKE=		YES

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../graphics/aalib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
