# $NetBSD: Makefile,v 1.4 2012/10/22 21:52:39 othyro Exp $
#

DISTNAME=	tkpng0.9
PKGNAME=	${DISTNAME:S/tkpng/tkpng-/}
CATEGORIES=	graphics
MASTER_SITES=	http://sourceforge.net/projects/tkpng/files/tkpng/0.9/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.muonics.com/FreeStuff/TkPNG/
COMMENT=	Open source package that adds PNG photo image support to Tcl/Tk
LICENSE=	2-clause-bsd # ?

GNU_CONFIGURE=	yes

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
