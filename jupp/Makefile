# $NetBSD: Makefile,v 1.7 2012/10/01 21:43:26 asau Exp $
#

DISTNAME=	joe-3.1jupp20
PKGNAME=	${DISTNAME:S/jupp/./:S/joe/jupp/}
CATEGORIES=	editors
MASTER_SITES=	http://www.mirbsd.org/MirOS/dist/jupp/ \
		http://pub.allbsd.org/MirOS/dist/jupp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.mirbsd.org/jupp.htm
COMMENT=	The portable version of joe from the MirOS project
LICENSE=	gnu-gpl-v1
WRKSRC=		${WRKDIR}/jupp

CONFLICTS+=	joe-[0-9]*
BUILD_DEPENDS+=	mksh-[0-9]*:../../shells/mksh

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/examples

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
