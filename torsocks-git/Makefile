# $NetBSD: Makefile,v 1.4 2015/05/24 13:55:43 i3enedek Exp $

DISTNAME=	torsocks
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitweb.torproject.org/torsocks.git
COMMENT=	Library to torify applications
LICENSE=	gnu-gpl-v2


GIT_REPOSITORIES=	master
GIT_REPO.master=	https://git.torproject.org/torsocks.git
GIT_MODULE.master=	torsocks


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
.include "../../wip/mk/git-package.mk"
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
