# $NetBSD: Makefile,v 1.6 2012/09/28 05:24:51 asau Exp $
#

DISTNAME=	xoo-0.8
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://labs.o-hand.com/sources/xoo/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://labs.o-hand.com/xoo/
COMMENT=	Graphical wrapper around Xnest/Xephyr

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CFLAGS=			-DPREFIX=\"${PREFIX}\"
CONFIGURE_ARGS+=	CFLAGS=${CFLAGS:M*:Q}

post-install:
	${INSTALL} -m 444 ${FILESDIR}/neo1973.png ${DESTDIR}${PREFIX}/share/xoo/neo1973.png
	${INSTALL} -m 444 ${FILESDIR}/neo1973.xml ${DESTDIR}${PREFIX}/share/xoo/neo1973.xml

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
