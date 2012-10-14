# $NetBSD: Makefile,v 1.3 2012/10/14 13:26:57 thomasklausner Exp $
#

DISTNAME=	Tktable2.10
PKGNAME=	${DISTNAME:S/Tktable/tktable-/}
CATEGORIES=	x11
MASTER_SITES=	http://sourceforge.net/projects/tktable/files/tktable/2.10/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tktable.sourceforge.net/
COMMENT=	Full-featured 2D table widget for Tk
#LICENSE=	# TODO: (see ${WRKSRC}/license.txt)

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib/tcl8.5 \
			--with-tk=${BUILDLINK_PREFIX.tk}/lib/tk8.5 \
			--enable-threads

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
