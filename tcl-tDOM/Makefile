# $NetBSD: Makefile,v 1.7 2012/01/01 22:23:49 mwilhelmy Exp $
#

DISTNAME=	tDOM-0.8.3
PKGNAME=	tcl-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://github.com/downloads/tDOM/tdom/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://tdom.github.com/
COMMENT=	High performance XML data handling library for Tcl using Expat
LICENSE=	mpl-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
