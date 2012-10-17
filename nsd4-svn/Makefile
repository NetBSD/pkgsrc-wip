# $NetBSD: Makefile,v 1.4 2012/10/17 02:35:18 asau Exp $
#

DISTNAME=	nsd4-${VERSION}
CATEGORIES=	net security
MASTER_SITES=	# not defined

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/projects/nsd/
COMMENT=	Name Server Daemon 4 (trunk)
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.openssl+= openssl>=0.9.7

PKG_OPTIONS_VAR=        PKG_OPTIONS.nsd
PKG_SUPPORTED_OPTIONS=  inet6
PKG_SUGGESTED_OPTIONS=  inet6

.include "../../mk/bsd.options.mk"

USE_TOOLS+=     aclocal autoconf automake autoheader gmake gm4 autoreconf
#USE_LIBTOOL=	yes

SVN_REPOSITORIES=	nsd
SVN_ROOT.nsd=		http://www.nlnetlabs.nl/svn/nsd/trunk/
SVN_MODULE.nsd=		NSD4
VERSION=		4.0a
NO_CHECKSUM=		yes

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

WRKSRC=			${WRKDIR}/NSD4

PKG_SYSCONFSUBDIR=	nsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=--localstatedir=${VARBASE}
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif
CONFIGURE_ARGS+=--enable-bind8-stats
CONFIGURE_ARGS+=--with-ratelimit

CONFIGURE_ARGS+=--with-pidfile=${VARBASE}/run/nsd.pid
CONFIGURE_ARGS+=--with-user=${NSD_USER}
CONFIGURE_ARGS+=--with-dbfile=${VARBASE}/nsd/nsd.db
CONFIGURE_ARGS+=--with-difffile=${VARBASE}/nsd/nsd-ixfr.db
CONFIGURE_ARGS+=--with-xfrdfile=${VARBASE}/nsd/nsd-xfrd.state
CONFIGURE_ARGS+=--with-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=--with-ssl=${BUILDLINK_PREFIX.openssl}

RCD_SCRIPTS=    nsd

NSD_USER?=      nsd
NSD_GROUP?=     nsd

PKG_GROUPS=     ${NSD_GROUP}
PKG_USERS=      ${NSD_USER}:${NSD_GROUP}

CONF_FILES+=	share/examples/nsd/nsd.conf ${PKG_SYSCONFDIR}/nsd.conf

INSTALLATION_DIRS=      share/examples/nsd
INSTALLATION_DIRS+=	${VARBASE}/nsd

pre-configure:
	cd ${WRKSRC} && autoreconf -i

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/nsd.zones2nsd.conf \
		${DESTDIR}${PREFIX}/share/examples/nsd

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
