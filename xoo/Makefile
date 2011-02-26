# $NetBSD: Makefile,v 1.1 2011/02/26 15:15:18 khorben Exp $
#

DISTNAME=	xoo-0.8
CATEGORIES=	x11
MASTER_SITES=	http://labs.o-hand.com/sources/xoo/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://labs.o-hand.com/xoo/
COMMENT=	Graphical wrapper around Xnest/Xephyr

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
CFLAGS=
CFLAGS+=	-DPREFIX=\"${PREFIX:Q}\"
CONFIGURE_ARGS+=CFLAGS=${CFLAGS:M*:Q}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
