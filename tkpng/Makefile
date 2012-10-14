# $NetBSD: Makefile,v 1.3 2012/10/14 13:26:57 thomasklausner Exp $
#

DISTNAME=	tkpng0.9
PKGNAME=	${DISTNAME:S/tkpng/tkpng-/}
CATEGORIES=	graphics
MASTER_SITES=	http://sourceforge.net/projects/tkpng/files/tkpng/0.9/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.muonics.com/FreeStuff/TkPNG/
COMMENT=	Open source package that adds PNG photo image support to Tcl/Tk
#LICENSE=	# TODO: (see ${WRKSRC}/${DISTNAME}/license.terms)

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib/tcl8.5 \
			--with-tk=${BUILDLINK_PREFIX.tk}/lib/tk8.5 \
			--enable-threads

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
