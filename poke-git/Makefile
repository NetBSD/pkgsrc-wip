# $NetBSD$

GNULIB_HASH=	160d5e7d9a64a29a52d4821fd0ef2136d7e2102a
JITTER_HASH=	37b32d525e91c855b9836c62394310f8af73d50e

PKGNAME=	poke-git-0.20201118
DISTNAME=	poke-750c179b57ee8ea522f599fa5ea1efb31ba0b31e
CATEGORIES=	textproc devel
MASTER_SITES=	https://git.savannah.gnu.org/cgit/poke.git/snapshot/
DISTFILES=	${DISTNAME}.tar.gz
DISTFILES+=	gnulib-${GNULIB_HASH}.tar.gz
DISTFILES+=	jitter-${JITTER_HASH}.tar.gz
SITES.gnulib-${GNULIB_HASH}.tar.gz= \
		https://git.savannah.gnu.org/cgit/gnulib.git/snapshot/
SITES.jitter-${JITTER_HASH}.tar.gz= \
		http://git.ageinghacker.net/jitter/snapshot/

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	http://www.jemarch.net/poke
COMMENT=	Extensible editor for structured binary data
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake makeinfo gawk
USE_TOOLS+=	autoconf automake aclocal autoheader
USE_TOOLS+=	flex bison

TOOL_DEPENDS+=	bison>=3.6:../../devel/bison

TOOLS_PLATFORM.bison=
TOOLS_PLATFORM.bison-yacc=

BOOTSTRAP_FLAGS+=	--skip-po --no-git
BOOTSTRAP_FLAGS+=	--gnulib-srcdir=${WRKSRC}/gnulib

CONFIGURE_FLAGS+=	--enable-mi

post-extract:
	rmdir ${WRKSRC}/gnulib ${WRKSRC}/jitter
	mv ${EXTRACT_DIR}/gnulib-${GNULIB_HASH} ${WRKSRC}/gnulib
	mv ${EXTRACT_DIR}/jitter-${JITTER_HASH} ${WRKSRC}/jitter

pre-configure:
	cd ${WRKSRC} && ${SH} ./bootstrap ${BOOTSTRAP_FLAGS}

.include "options.mk"

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
