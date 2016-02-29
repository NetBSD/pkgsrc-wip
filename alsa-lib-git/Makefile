# $NetBSD: Makefile,v 1.16 2016/02/18 15:15:57 wiz Exp $

DISTNAME=	alsa-lib-1.1.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture (ALSA)
LICENSE=	gnu-lgpl-v2.1

GIT_REPOSITORIES+=	alsa
GIT_REPO.alsa=		git://git.alsa-project.org/alsa-lib.git

WRKSRC=		${WRKDIR}/alsa

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake autoconf automake

PKGCONFIG_OVERRIDE+=	utils/alsa.pc.in

CONFIGURE_ARGS+=	--disable-python

LIBS.SunOS+=		-lsocket -lnsl
CPPFLAGS.SunOS+=	-std=c99 -D_POSIX_C_SOURCE=200112L
CPPFLAGS.SunOS+=	-D__EXTENSIONS__ -DBSD_COMP -DMAP_FILE=0
CPPFLAGS.SunOS+=	-D__u32=uint32_t -D__u64=uint64_t
CPPFLAGS.SunOS+=	-Dbswap_64=BSWAP_64 -Dbswap_32=BSWAP_32 -Dbswap_16=BSWAP_16

CPPFLAGS.NetBSD+=	-D__u32=uint32_t -D__u64=uint64_t -Dbswap_16=bswap16 -Dbswap_32=bswap32 -Dbswap_64=bswap64
CPPFLAGS.FreeBSD+=	-D__u32=uint32_t -D__u64=uint64_t -Dbswap_16=bswap16 -Dbswap_32=bswap32 -Dbswap_64=bswap64

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--without-versioned
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=Versions
.endif

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
