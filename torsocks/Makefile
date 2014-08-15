# $NetBSD: Makefile,v 1.3 2014/08/15 20:59:39 leot1990 Exp $

DISTNAME=	torsocks-2.0.0
CATEGORIES=	net security
MASTER_SITES=	-https://github.com/dgoulet/torsocks/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dgoulet/torsocks/
COMMENT=	Library to torify applications
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	torsocks

USE_TOOLS+=	autoreconf autoconf automake
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV+=	LIBC_PATH=/lib/libc.so

SUBST_CLASSES+=			configure
SUBST_STAGE.configure=		pre-configure
SUBST_MESSAGE.configure=	Fixing configure.ac
SUBST_FILES.configure=		configure.ac
SUBST_SED.configure=		-e '/test/ s/ == / = /g'

.include "../../mk/bsd.prefs.mk"

# gethostbyaddr(3) in NetBSD < 7.0 prototype is:
#     struct hostent *
#     gethostbyaddr(const char *addr, socklen_t len, int type);
# torsocks and The Open Group expects:
#     struct hostent *
#     gethostbyaddr(const void *addr, socklen_t len, int type);
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[0-6].*)
SUBST_CLASSES+=		lib
SUBST_STAGE.lib=	pre-configure
SUBST_MESSAGE.lib=	Fixing src/lib/torsocks.h
SUBST_FILES.lib=	src/lib/torsocks.h
SUBST_SED.lib=		-e '/LIBC_GETHOSTBYADDR_SIG/ s/const void \*addr/const char *addr/'
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
