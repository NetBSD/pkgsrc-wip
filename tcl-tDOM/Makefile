# $NetBSD: Makefile,v 1.1.1.1 2010/03/24 08:46:31 phonohawk Exp $
#

DISTNAME=	tDOM-0.8.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.tdom.org/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.tdom.org/
COMMENT=	High performance XML data processing for Tcl
LICENSE=	mpl-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
