# $NetBSD$

GITHUB_TAG=	v0.10
DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG:S,^v,,}
PKGNAME=	${DISTNAME:S,outils,signify,}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_PROJECT=	outils

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://flak.tedunangst.com/post/signify
COMMENT=	Cryptographically sign and verify files, from OpenBSD
LICENSE=	original-bsd AND modified-bsd AND isc AND public-domain

USE_TOOLS+=	gmake
MAKEFLAGS+=	ALL=src/usr.bin/signify/signify

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
MAKE_DIRS+=		${PKG_SYSCONFDIR}/signify

WRKSRC=		${WRKDIR}/${DISTNAME}
OUTDIR:=	${WRKSRC}/src/usr.bin/signify
LIBSRCDIR:=	${WRKSRC}/src/liboutils

.include "../../mk/bsd.prefs.mk"
# do not hard-code configuration dir
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	${OUTDIR}/signify.c
SUBST_FILES.paths+=	${OUTDIR}/signify.1
SUBST_SED.paths=	-e 's|/etc/signify|${PKG_SYSCONFDIR}/signify|g'

.if ${OPSYS} == "SunOS"
# SunOS stdint(3) doesn't provide `u_int*' typedefs
SUBST_CLASSES+=		ints
SUBST_STAGE.ints=	pre-configure
SUBST_FILES.ints+=	${LIBSRCDIR}/*.c
SUBST_FILES.ints+=	${LIBSRCDIR}/include/*.h
SUBST_SED.ints=		-e 's|u_int|uint|g'

# link against libresolv to fix referencing
# errors to `__b64_ntop' | `__b64_pton'
MAKEFLAGS+=	LIBS='-lresolv -lrt -lm'
.endif

post-patch:
.if ${OPSYS} == "NetBSD"
# The sys/* overrides are not needed on NetSD
	${RM} ${WRKSRC}/src/liboutils/include/sys/*

.elif ${OPSYS} == "SunOS"
# Solaris lacks MIN/MAX macros in sys/param.h
	cd ${LIBSRCDIR} && ${CP} ${FILESDIR}/minmax.h . 					\
	&& ${CAT} outils.h >> minmax.h && ${MV} minmax.h outils.h
.endif

do-install:
	${INSTALL_PROGRAM} ${OUTDIR}/signify ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${OUTDIR}/signify.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
