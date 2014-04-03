# $NetBSD: Makefile,v 1.7 2014/04/03 01:21:22 outpaddling Exp $

DISTNAME=	ape-3.5.2
CATEGORIES=	editors
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/
COMMENT=	Another Programmer's Editor
#LICENSE=	BSD license, but which one?

MAKE_ENV+=	STAGEDIR=${DESTDIR}

pre-build:
	cd ${WRKSRC} && ${MAKE} LOCALBASE=${PREFIX} depend

.include "../../wip/libpare/buildlink3.mk"
.include "../../wip/libbacon/buildlink3.mk"
.include "../../wip/twintk/buildlink3.mk"
.include "../../wip/webbrowser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
