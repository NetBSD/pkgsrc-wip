# $NetBSD: Makefile,v 1.18 2006/10/29 08:32:57 shattered Exp $

DISTNAME=	umix-1.0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=umix/}

MAINTAINER=	cez@compsoc.man.ac.uk
HOMEPAGE=	http://umix.sourceforge.net/
COMMENT=	Adjust mix levels

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake automake pkg-config
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

LIBS+=			${LIBOSSAUDIO}

pre-configure:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --automake
	cd ${WRKSRC} && automake --add-missing
	cd ${WRKSRC} && autoconf

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
