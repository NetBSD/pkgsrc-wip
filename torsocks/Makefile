# $NetBSD: Makefile,v 1.4 2015/05/24 13:55:43 i3enedek Exp $

DISTNAME=	torsocks_2.2.0.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/torsocks/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitweb.torproject.org/torsocks.git
COMMENT=	Library to torify applications
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-conf=${PKG_SYSCONFDIR}/torsocks.conf

# XXX: Is this portable?
CONFIGURE_ENV+=	LIBC_PATH=/lib/libc.so

EGDIR=		${PREFIX}/share/examples/torsocks
CONF_FILES=	${EGDIR}/torsocks.conf \
		${PKG_SYSCONFDIR}/torsocks.conf

SUBST_CLASSES+=			configure
SUBST_STAGE.configure=		pre-configure
SUBST_MESSAGE.configure=	Fixing non-standard test(1) == operator
SUBST_FILES.configure=		configure
SUBST_SED.configure=		-e '/test/ s/ == / = /g'

SUBST_CLASSES+=			confdir
SUBST_STAGE.confdir=		pre-configure
SUBST_MESSAGE.confdir=		Adjusting confdir
SUBST_FILES.confdir=		doc/Makefile.in
SUBST_SED.confdir=		-e '/^confdir/ s;/tor;;'

SUBST_CLASSES+=			conffile
SUBST_STAGE.conffile=		pre-configure
SUBST_MESSAGE.conffile=		Adjusting DEFAULT_CONF_FILE
SUBST_FILES.conffile=		src/common/defaults.h
SUBST_SED.conffile=		-e '/DEFAULT_CONF_FILE/ s;"/tor/";"/";'

.include "../../mk/bsd.prefs.mk"

# XXX: gethostbyaddr(3) in NetBSD < 7.0 prototype is:
# XXX:     struct hostent *
# XXX:     gethostbyaddr(const char *addr, socklen_t len, int type);
# XXX: torsocks and The Open Group expects:
# XXX:     struct hostent *
# XXX:     gethostbyaddr(const void *addr, socklen_t len, int type);
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[0-6].*)
SUBST_CLASSES+=		lib
SUBST_STAGE.lib=	pre-configure
SUBST_MESSAGE.lib=	Fixing gethostbyaddr() prototype
SUBST_FILES.lib=	src/lib/torsocks.h
SUBST_SED.lib=		-e '/LIBC_GETHOSTBYADDR_SIG/ s/const void \*addr/const char *addr/'
.endif

TEST_TARGET=	check

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/torsocks.conf \
	    ${DESTDIR}${EGDIR}/torsocks.conf

.include "../../mk/bsd.pkg.mk"
