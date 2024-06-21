# $NetBSD$

DISTNAME=	pleroma-v2.6.3
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	www
MASTER_SITES=	https://git.pleroma.social/pleroma/pleroma/-/archive/v2.6.3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pleroma.social/
COMMENT=	Lightweight ActivityPub server, written in Elixir
LICENSE=	gnu-agpl-v3

# pin runtime versions here to avoid autoresolving
ELIXIR_VERSION=	elixir<=16
ERLANG_VERSION=	erlang<=27

# Elixir will be compiled and packaged alongside
# main pleroma's code
TOOL_DEPENDS+=	${ELIXIR_VERSION}:../../lang/elixir

# pax, find and gmake are required for pleroma.mk;
# rest and gmake itself will be used for Elixir deps.
# Erlang is hard dependency here since there are few
# binary deps which link to it. Although Mix.Release
# supports bundling erts together with compiled app
# code, this will require overriding LD_LIBRARY_PATH
# and is not guaranteed to work.
DEPENDS+=	libvips-[0-9]*:../../graphics/libvips
DEPENDS+=	file-[0-9]*:../../sysutils/file
DEPENDS+=	${ERLANG_VERSION}:../../lang/erlang

# These are outlined in official pleroma docs for NetBSD.
# mksh can be replaced with ksh93
DEPENDS+=	sudo-[0-9]*:../../security/sudo
DEPENDS+=	mksh-[0-9]*:../../shells/mksh
DEPENDS+=	postgresql15-client-[0-9]*:../../databases/postgresql15-client

# NB: is it really needed?
#DEPENDS+=	postgresql15-contrib-[0-9]*:../../databases/postgresql15-contrib

USE_TOOLS+=	pax gmake find sed
USE_LANGUAGES=	c c++
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	rebar3-[0-9]*:../../devel/rebar3

# this is crucial as hex downloads all stuff from the registry
ALLOW_NETWORK_ACCESS=	yes

# user and rc.d management
#RCD_SCRIPTS=			pleroma
PLEROMA_USER?=			pleroma
PLEROMA_GROUP?=			pleroma
PLEROMA_SHELL?=			${PREFIX}/bin/mksh
PLEROMA_PREFIX?=		${PREFIX}/lib/pleroma
PKG_GROUPS=			${PLEROMA_GROUP}
PKG_USERS=			${PLEROMA_USER}:${PLEROMA_GROUP}
PKG_GROUPS_VARS+=		PLEROMA_GROUP
PKG_USERS_VARS+=		PLEROMA_USER
PKG_GECOS.${PLEROMA_USER}=	Pleroma server user
PKG_HOME.${PLEROMA_USER}=	${PLEROMA_PREFIX}
PKG_SHELL.${PLEROMA_USER}=	${PLEROMA_SHELL}

OWN_DIRS+=		${PLEROMA_PREFIX}
OWN_DIRS+=		${PREFIX}/etc/pleroma
OWN_DIRS+=		${PREFIX}/var/pleroma
OWN_DIRS+=		${PREFIX}/share/examples/pleroma
OWN_DIRS_PERMS+=	${PLEROMA_PREFIX} ${PLEROMA_USER} ${PLEROMA_GROUP} 0700
OWN_DIRS_PERMS+=	${PREFIX}/etc/pleroma ${PLEROMA_USER} ${PLEROMA_GROUP} 0700
OWN_DIRS_PERMS+=	${PREFIX}/var/pleroma ${PLEROMA_USER} ${PLEROMA_GROUP} 0700
OWN_DIRS_PERMS+=	${PREFIX}/share/examples/pleroma ${PLEROMA_USER} ${PLEROMA_GROUP} 0700

# fix bin script
SUBST_CLASSES+=		binpath
SUBST_STAGE.binpath=	pre-install
SUBST_MESSAGE.binpath=	Fixing pleroma script absolute path
SUBST_FILES.binpath=	release/bin/pleroma
SUBST_SED.binpath=	-e "s:^RELEASE_ROOT=.*:RELEASE_ROOT=${PREFIX}/lib/pleroma:g"

# fix config path
SUBST_CLASSES+=		confpath
SUBST_STAGE.confpath=	pre-install
SUBST_MESSAGE.confpath=	Fixing pleroma config file path
SUBST_FILES.confpath=	release/releases/${PKGVERSION}/env.sh
SUBST_SED.confpath=	-e "s:PLEROMA_CONF_REPLACE_ME:${PREFIX}/etc/pleroma/config.exs:g"

# target makefile and make environment
MAKE_FILE=	pleroma.mk
MAKE_ENV+=	MIX_ENV="prod"
MAKE_ENV+=	MIX="${PREFIX}/bin/mix"
MAKE_ENV+=	MIX_REBAR3="${PREFIX}/bin/rebar3"
MAKE_ENV+=	VIX_COMPILATION_MODE="PLATFORM_PROVIDED_LIBVIPS"
MAKE_ENV+=	TARGET_PREFIX="${DESTDIR}${PREFIX}"
MAKE_ENV+=	PLEROMA_USER="${PLEROMA_USER}"
MAKE_ENV+=	PLEROMA_GROUP="${PLEROMA_GROUP}"
MAKE_ENV+=	PLEROMA_SHELL="${PLEROMA_SHELL}"
MAKE_ENV+=	PLEROMA_PREFIX="${DESTDIR}${PLEROMA_PREFIX}"
MAKE_ENV+=	PLEROMA_VERSION="${PKGVERSION}"

# Elixir seems to be picky if it was compiled on the
# system with another endianness:
# https://github.com/elixir-lang/elixir/issues/2785
.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} != "big" && ${MACHINE_ENDIAN} != "little"
.  error "Unknown MACHINE_ENDIAN: ${MACHINE_ENDIAN}"
.else
ELIXIR_ENDIAN=${MACHINE_ENDIAN}
.endif

# Error out if trying to crosscompile for foreign endianness:
# in this case, native (qemu/real hw) build needs to be used.
pre-configure:
	${RUN} ./check_endianness.sh :${ELIXIR_ENDIAN}
	${RUN} ${CP} ./pleroma.mk ${WRKSRC}


#	${RUN} ${CHOWN} -R ${PLEROMA_USER}:${PLEROMA_GROUP} ${PLEROMA_PREFIX}
#	${RUN} ${CHOWN} ${PLEROMA_USER}:${PLEROMA_GROUP} ${PREFIX}/bin/pleroma

# needed for native erlang modules
.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# [../lang/elixir/Makefile]
# erlang chooses latin1 or utf8 encoding for file names depending on
# the character encoding, and elixir requires utf8.  Force erl to
# choose utf8.  We'd like to set LC_CTYPE, but we need to override the
# LC_ALL set by bsd.pkg.mk.
ALL_ENV+=	LC_ALL="en_US.UTF-8"