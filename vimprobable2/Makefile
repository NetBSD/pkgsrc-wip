# $NetBSD: Makefile,v 1.3 2013/06/09 12:35:59 leot1990 Exp $
#

DISTNAME=	vimprobable2_1.3.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vimprobable/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vimprobable.org/
COMMENT=	WebKit based web browser that behaves like Vimperator
LICENSE=	mit

USE_TOOLS+=	gmake perl pkg-config
WRKSRC=		${WRKDIR}/vimprobable2

MAKE_ENV+=	MANDIR="${PREFIX}/${PKGMANDIR}"

.include "options.mk"

.include "../../net/libsoup24/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
