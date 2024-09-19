# $NetBSD: Makefile,v 1.16 2012/12/09 20:21:52 othyro Exp $
#

DISTNAME=	xinetd-2.3.15
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xinetd.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xinetd.org/
COMMENT=	Secure replacement for inetd
#LICENSE=	# XXX TODO see ${WRKSRC}/COPYRIGHT

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILD_TARGET=		build
CONFIGURE_ARGS+=	--with-loadavg

.include "../../mk/bsd.prefs.mk"

# OPTIONS
BUILD_DEFS+=		XINETD_USE_TCPWRAPPER
XINETD_USE_TCPWRAPPER?=	NO
.if !empty(XINETD_USE_TCPWRAPPER:M[yY][eE][sS])
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}/lib
.endif

RCD_SCRIPTS=		xinetd
# Some weird quoting in Makefile.in makes this necessary.
CPPFLAGS+=		-DDEFAULT_CONFIG_FILE="\"${PKG_SYSCONFDIR}/etc/xinetd.conf\""

USE_TOOLS+=		perl:run
REPLACE_PERL+=		xinetd/xconv.pl

EGDIR=			share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${EGDIR}/xinetd.d

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/xinetd.conf \
		${DESTDIR}${PREFIX}/share/examples/xinetd/
	${INSTALL_DATA} ${WRKSRC}/contrib/xinetd.d/* \
		${DESTDIR}${PREFIX}/share/examples/xinetd/xinetd.d/

.if !empty(XINETD_USE_TCPWRAPPER:M[yY][eE][sS])
.include "../../security/tcp_wrappers/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
