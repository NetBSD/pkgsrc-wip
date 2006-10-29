# $NetBSD: Makefile,v 1.21 2006/10/29 08:32:58 shattered Exp $
#

DISTNAME=		ZSNESS_1012
PKGNAME=		zsnes-20061012
CATEGORIES=		emulators
MASTER_SITES=		http://files.ipherswipsite.com/zsnes/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://zsnes.ipherswipsite.com/
COMMENT=		Super NES emulator, development version

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

WRKSRC=			${WRKDIR}
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake autoconf automake
USE_LANGUAGES=		c c++
ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
CONFIGURE_ENV+=		force_arch=k8
#BUILD_DEPENDS+=		yasm-[0-9]*:../../devel/yasm
#CONFIGURE_ENV+=		NASMPATH=${LOCALBASE}/bin/yasm
#.else
#BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm
.endif

pre-configure:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && autoconf

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
