# $NetBSD: Makefile,v 1.1.1.1 2003/09/17 15:33:29 xtraeme Exp $

DISTNAME=	hydrogen-0.8.0
PKGNAME=	${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hydrogen/}

MAINTAINER=	chris.wareham@btinternet.com
HOMEPAGE=	http://hydrogen.sourceforge.net/
COMMENT=	Real time drum machine/sequencer

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-alsa-seq
CONFIGURE_ARGS+=	--disable-jack-support

.include "../../audio/libhydrogen/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
