# $NetBSD: Makefile,v 1.2 2007/11/25 20:59:10 hoka_adam Exp $
#

DISTNAME=	joe-3.1jupp8.cpio
PKGNAME=	jupp-3.1.8
CATEGORIES=	editors
MASTER_SITES=	http://www.mirbsd.org/MirOS/dist/jupp/ \
				http://pub.allbsd.org/MirOS/dist/jupp/
EXTRACT_SUFX=	.gz

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.mirbsd.org/jupp.htm
COMMENT=	The portable version of joe from the MirOS project
WRKSRC=		${WRKDIR}/jupp
CONFLICTS+=	joe-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=    --sysconfdir=${PREFIX:Q}/share/examples

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
