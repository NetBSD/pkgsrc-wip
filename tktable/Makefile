# $NetBSD: Makefile,v 1.4 2012/10/22 22:13:20 othyro Exp $
#

DISTNAME=	Tktable2.10
PKGNAME=	${DISTNAME:S/Tktable/tktable-/}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://sourceforge.net/projects/tktable/files/tktable/2.10/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tktable.sourceforge.net/
COMMENT=	Full-featured 2D table widget for Tk
#LICENSE=	# TODO: (see ${WRKSRC}/license.txt) 2-clause-bsd + bourbon_ware

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11}/include \
			--x-libraries=${BUILDLINK_PREFIX.libX11}/lib

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
