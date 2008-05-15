# $NetBSD: Makefile,v 1.4 2008/05/15 22:26:43 hoka_adam Exp $
#

DISTNAME=	joe-3.1jupp9.cpio
PKGNAME=	jupp-3.1.9
CATEGORIES=	editors
MASTER_SITES=	http://www.mirbsd.org/MirOS/dist/jupp/ \
		http://pub.allbsd.org/MirOS/dist/jupp/
EXTRACT_SUFX=	.gz

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.mirbsd.org/jupp.htm
COMMENT=	The portable version of joe from the MirOS project
WRKSRC=		${WRKDIR}/jupp

CONFLICTS+=	joe-[0-9]*
BUILD_DEPENDS+=	mksh-[0-9]*:../../shells/mksh

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX:Q}/share/examples

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
