# $NetBSD: Makefile,v 1.9 2014/01/06 22:11:01 joerg Exp $
#

DISTNAME=	flite-2.0.0-release
PKGNAME=	${DISTNAME:S/-release//}
#PKGREVISION=	3
CATEGORIES=	audio
#MASTER_SITES=	http://www.speech.cs.cmu.edu/flite/packed/flite-1.3/
MASTER_SITES=	http://festvox.org/flite/packed/flite-2.0/	
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.speech.cs.cmu.edu/flite/
COMMENT=	Small and fast run-time synthesis engine

CONFLICTS+=		flite-1.3:../../audio/flite
# Error opening output file '[...]/cmu_us_kal_diphone.o': No such file or directory
MAKE_JOBS_SAFE=		no
CFLAGS+=		-fPIC
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

#CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/flite
#CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib
#CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-sockets
CONFIGURE_ARGS+=	--with-audio=pulseaudio 
CONFIGURE_ARGS+=	--with-lang 
CONFIGURE_ARGS+=	--with-pic 
CONFIGURE_ARGS+=	--with-vox 
CONFIGURE_ARGS+=	--with-lex 
CONFIGURE_ARGS+=	--with-langvox=default

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
