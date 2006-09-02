# $NetBSD: Makefile,v 1.9 2006/09/02 12:05:39 gschwarz Exp $

DISTNAME=	traceroute-nanog-6.4.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.login.com/pub/software/traceroute/
DISTFILES=	traceroute.c
DIST_SUBDIR=	traceroute-nanog

# for the man page:
PATCH_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/traceroute-nanog/}
PATCHFILES=	traceroute-nanog_6.3.10-2.diff.gz

COMMENT=	Traceroute implementation
MAINTAINER=	schwarz@NetBSD.org

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES

TRN_EXTRALIBS=

.include "../../mk/bsd.prefs.mk"
.if empty(PKGSRC_COMPILER:Mgcc*)
CPPFLAGS+=	-D__attribute__=
.endif

.if ${OPSYS} == "SunOS"
.if ${OS_VERSION} >= 5.0
.if ${OS_VERSION} != 5.4
CPPFLAGS+=	-DSOLARIS
TRN_EXTRALIBS+=	-lresolv -lsocket -lnsl
.endif
.if ${LOWER_ARCH} == "i386"
CPPFLAGS+=	-DBYTESWAP_IP_LEN
.endif
.endif
.endif
.if ${OPSYS} == "Linux"
TRN_EXTRALIBS+=	-lresolv
.endif

.if ${OPSYS} == "Darwin"
CPPFLAGS+=	-DBIND_8_COMPAT -DRA_SERVICE=\"nicname\"
.endif

.if !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=	-Dsocklen_t=int
# needs snprintf()
.include "../../pkgtools/libnbcompat/buildlink3.mk"
TRN_EXTRALIBS+=	${BUILDLINK_LDADD.libnbcompat}
.endif

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-extract:
		${CP} ${DISTDIR}/${DIST_SUBDIR}/traceroute.c ${WRKSRC}
do-build:
		cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} traceroute.c -o traceroute-nanog ${LDFLAGS} -lm ${TRN_EXTRALIBS}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/traceroute-nanog ${PREFIX}/sbin
		${INSTALL_MAN} ${WRKDIR}/traceroute-nanog-6.3.10/debian/traceroute-nanog.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
