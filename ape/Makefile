# $NetBSD: Makefile,v 1.2 2013/11/10 02:34:39 outpaddling Exp $
#

DISTNAME=	ape-3.5.1
CATEGORIES=	editors
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

EXTRACT_SUFX=	.tar.xz

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include "../../wip/libpare/buildlink3.mk"
.include "../../wip/libbacon/buildlink3.mk"
.include "../../wip/twintk/buildlink3.mk"
.include "../../wip/webbrowser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
