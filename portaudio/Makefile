# $NetBSD: Makefile,v 1.8 2013/05/08 23:57:17 othyro Exp $

DISTNAME=	pa_stable_v19_20111121
PKGNAME=	${DISTNAME:S/pa_stable_v19_/portaudio-19./1}
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.portaudio.com/
COMMENT=	Portable cross-platform Audio API
LICENSE=	mit

NOT_FOR_PLATFORM=	Interix-*-*
CONFLICTS+=		portaudio<19

WRKSRC=			${WRKDIR}/${PKGBASE}
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CFLAGS.Darwin=		-Ipablio

.include "options.mk"

CONFIGURE_ARGS+=	--enable-cxx

.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
RT_LIB_SCHED=		-lrt
.else
RT_LIB_SCHED=		# empty
.endif
MAKE_ENV+=		RT_LIB_SCHED=${RT_LIB_SCHED}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
