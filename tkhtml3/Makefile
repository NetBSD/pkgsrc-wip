# $NetBSD: Makefile,v 1.5 2012/10/22 22:20:44 othyro Exp $
#

DISTNAME=	tkhtml3-alpha-16
PKGNAME=	${DISTNAME:S/alpha-/1.0alpha/}
CATEGORIES=	www
MASTER_SITES=	http://tkhtml.tcl.tk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tkhtml.tcl.tk/
COMMENT=	Tk widget displaying content formatted to HTML and CSS standards
LICENSE=	modified-bsd # ?

WRKSRC=		${WRKDIR}/htmlwidget
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11}/include \
			--x-libraries=${BUILDLINK_PREFIX.libX11}/lib

.include "options.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
