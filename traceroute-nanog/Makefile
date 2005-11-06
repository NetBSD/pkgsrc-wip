# $NetBSD: Makefile,v 1.5 2005/11/06 22:16:41 gschwarz Exp $

DISTNAME=	traceroute-nanog-6.3.10
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.login.com/pub/software/traceroute/beta/
DISTFILES=	traceroute.c
DIST_SUBDIR=	traceroute-nanog

# for the man page:
PATCH_SITES=	http://ftp.debian.org/debian/pool/main/t/traceroute-nanog/
PATCHFILES=	traceroute-nanog_6.3.10-2.diff.gz

COMMENT=	Traceroute implementation
MAINTAINER=	schwarz@NetBSD.org

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES

EXTRALIBS=

.include "../../mk/bsd.prefs.mk"
.if empty(PKGSRC_COMPILER:Mgcc*)
CPPFLAGS+=	-D__attribute__=
.endif
.if ${OPSYS} == "SunOS"
.if ${OS_VERSION} >= 5.0
.if ${OS_VERSION} != 5.4
CPPFLAGS+=	-DSOLARIS
EXTRALIBS+=	-lresolv -lsocket -lnsl
.endif
.if ${LOWER_ARCH} == "i386"
CPPFLAGS+=	-DBYTESWAP_IP_LEN
.endif
.endif
.endif
.if ${OPSYS} == "Linux"
EXTRALIBS+=	-lresolv
.endif
.if ${OPSYS} == "Darwin"
CPPFLAGS+=	-DBIND_8_COMPAT -DRA_SERVICE=\"nicname\"
.endif

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-extract:
		${CP} ${DISTDIR}/${DIST_SUBDIR}/traceroute.c ${WRKSRC}
do-build:
		cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} traceroute.c -o traceroute-nanog ${LDFLAGS} -lm ${EXTRALIBS}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/traceroute-nanog ${PREFIX}/sbin
		${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/debian/traceroute-nanog.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
