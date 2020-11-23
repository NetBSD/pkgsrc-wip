# $NetBSD$

DISTNAME=	tor-0.4.5.2-alpha
PKGNAME=	${DISTNAME:S/tor/tordev/:S/-alpha//:S/-rc/rc0/}
CATEGORIES=	net security
MASTER_SITES=	https://dist.torproject.org/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://www.torproject.org/
COMMENT=	Anonymizing overlay network for TCP
LICENSE=	modified-bsd

USE_LANGUAGES=		c99
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:test pkg-config bash:test
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--program-suffix=-dev
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/tordev
CONFIGURE_ENV+=		CPP=${CPP:Q}
CONFIGURE_ENV+=		CONFDIR=${PKG_SYSCONFDIR}

# as of 0.4.5.2-alpha:
# FAIL: src/test/unittest_part2.sh
# FAIL: src/test/unittest_part8.sh
# FAIL: src/test/test_include.sh
#============================================================================
#Testsuite summary for tor 0.4.5.2-alpha
#============================================================================
## TOTAL: 33
## PASS:  26
## SKIP:  4
## XFAIL: 0
## FAIL:  3
## XPASS: 0
## ERROR: 0
TEST_TARGET=		check

TOR_USER?=		tordev
TOR_GROUP?=		tor
PKG_GECOS.${TOR_USER}=	Torifier
PKG_HOME.${TOR_USER}=	${VARBASE}/chroot/tordev
BUILD_DEFS+=		VARBASE
PKG_SYSCONFSUBDIR=	tordev

PKG_GROUPS_VARS+=	TOR_GROUP
PKG_USERS_VARS=		TOR_USER

RCD_SCRIPTS=		tordev
RCD_SCRIPT_SRC.tordev=	${FILESDIR}/tordev.in
PKG_GROUPS=		${TOR_GROUP}
PKG_USERS=		${TOR_USER}:${TOR_GROUP}
USER_GROUP=		${TOR_USER} ${TOR_GROUP}

OWN_DIRS_PERMS+=	${PKG_HOME.${TOR_USER}} ${USER_GROUP} 0700

CONF_FILES+=		${PREFIX}/share/examples/tordev/torrc.sample	\
			${PKG_SYSCONFDIR}/torrc

PRINT_PLIST_AWK+=	/^man\/man/ { $$0 = "$${PLIST.doc}" $$0 }
PRINT_PLIST_AWK+=	/^share\/doc/ { $$0 = "$${PLIST.doc}" $$0 }

FILES_SUBST+=		PKG_HOME=${PKG_HOME.${TOR_USER}}
FILES_SUBST+=		TOR_USER=${TOR_USER} TOR_GROUP=${TOR_GROUP}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

CHECK_PORTABILITY_SKIP+=	contrib/*

REPLACE_BASH+=		scripts/maint/checkShellScripts.sh
REPLACE_BASH+=		scripts/maint/run_check_subsystem_order.sh

REPLACE_PERL+=		scripts/maint/checkOptionDocs.pl.in
REPLACE_PERL+=		scripts/maint/checkSpace.pl
REPLACE_PERL+=		scripts/maint/checkOptionDocs.pl
REPLACE_PERL+=		scripts/coccinelle/test-operator-cleanup

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro)
CFLAGS+=		-c99
.endif

.include "../../archivers/zstd/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+= libevent>=2.0
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
