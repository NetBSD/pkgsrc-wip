# $NetBSD: Makefile,v 1.1.1.1 2003/09/17 15:32:25 xtraeme Exp $

DISTNAME=	libhydrogen-0.8.0
PKGNAME=	${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hydrogen/}

MAINTAINER=	chris.wareham@btinternet.com
HOMEPAGE=	http://hydrogen.sourceforge.net/
COMMENT=	Shared library for the Hydrogen drum machine

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-alsa-seq
CONFIGURE_ARGS+=	--disable-jack-support

.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
