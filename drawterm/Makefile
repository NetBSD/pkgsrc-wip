# $NetBSD$

DISTNAME=	snap
BUILD=		20220603
PKGNAME=	drawterm-${BUILD}
CATEGORIES=	x11 plan9
DIST_SUBDIR=	${PKGNAME_NOREV}-${BUILD}
MASTER_SITES=	https://git.9front.org/git/plan9front/drawterm/bee4db6507fdf31bddfa98d26a673e135dfd28ad/

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://drawterm.9front.org/
COMMENT=	Utility to connect to Plan9 CPU servers
LICENSE=	mit

USE_LANGUAGES=	c c99

MAKEFLAGS+=	X11=${X11BASE} CFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${PKGSRC_COMPILER:Mgcc}
MAKEFLAGS+=	CFLAGS+="-Wall -Wno-missing-braces -ggdb \
		-I${WRKSRC} -I${WRKSRC}/include -I${WRKSRC}/kern \
		-c -I${X11}/include -D_THREAD_SAFE ${PTHREAD} -O2"
MAKEFLAGS+=	LDFLAGS+="${PTHREAD} -lpthread"
.else
MAKEFLAGS+=	CFLAGS+="-I{WRKSRC} -I${WRKSRC}/include -I${WRKSRC}/kern"
MAKEFLAGS+=	CFLAGS+="-g -c -I${X11}/include -D_THREAD_SAFE -O2"
MAKEFLAGS+=	LDFLAGS+="-lpthread"
.endif

.if ${OPSYS:M*BSD}
MAKEFLAGS+=		CONF=${LOWER_OPSYS}
.  if ${OPSYS} == OpenBSD
MAKEFLAGS+=		CC?=cc
.  elif ${OPSYS} == FreeBSD
MAKEFLAGS+=		CC?=clang
.  endif

.elif ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
MAKEFLAGS+=	CONF=unix AUDIO=alsa
MAKEFLAGS+= LDADD="-L${X11}/lib64 -L${X11}/lib -lX11 -ggdb -lm -lasound"

.elif ${OPSYS} == "Darwin"
MAKEFLAGS+=	CONF=osx-x11 CC?=clang PTHREAD=''
MAKEFLAGS+=	LDADD="-L${X11}/lib -lX11 -ggdb"

# Developer Studio also runs on Oracle Linux
.elif !empty(PKGSRC_COMPILER:Msunpro)
MAKEFLAGS+=	CONF=sun

.elif ${OPSYS} == "SunOS"
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	Make.unix
SUBST_SED.paths=	-e 's,i.86/386,i86pc/amd64,'

.  if ${OPSYS} == "SunOS" && empty(PKGSRC_COMPILER:Msunpro)
# On Solaris 10, AUDIO=sun is most probably needed,
MAKEFLAGS+=	CONF=unix AUDIO=unix
MAKEFLAGS+=	LDADD="-L${X11}/lib/64 -L${X11}/lib -lX11 -lX11 -lrt \
		-lpthread -lsocket -lnsl"
.  endif

.elif ${OPSYS} == "IRIX" && !empty(PKGSRC_COMPILER:Mmipspro*)
MAKEFLAGS+=	CONF=irix CFLAGS+=-DIRIX

.else
.  if !exists(/dev/dsp*)
MAKEFLAGS+=	CONF=unix CC?=gcc
.  else
MAKEFLAGS+=	CONF=unix CC?=gcc AUDIO=unix
.  endif
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=	${WRKDIR}/drawterm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/drawterm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/drawterm.1 								\
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
