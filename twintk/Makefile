# $NetBSD: Makefile,v 1.2 2013/08/14 01:33:35 outpaddling Exp $
#

DISTNAME=	twintk-0.9.3
CATEGORIES=	devel
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../wip/libbacon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
