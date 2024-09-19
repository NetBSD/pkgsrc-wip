# $NetBSD$

POKE_HASH=	011d904fe39ef526dc9b0fe1553b643b4bdbcc5c
GNULIB_HASH=	5aca1898c9f62370142920be91992d4efe72bb7b
JITTER_HASH=	a1fb50a93964676501c3530e4b73a22906d53a96

PKGNAME=	poke-0.0.20210103
DISTNAME=	poke-${POKE_HASH}
CATEGORIES=	textproc devel
MASTER_SITES=	https://git.savannah.gnu.org/cgit/poke.git/snapshot/
DISTFILES=	poke-${POKE_HASH}.tar.gz
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
TOOLS_PLATFORM.flex=
TOOLS_PLATFORM.makeinfo=

BOOTSTRAP_FLAGS+=	--skip-po --no-git
BOOTSTRAP_FLAGS+=	--gnulib-srcdir=${WRKSRC}/gnulib
BOOTSTRAP_FLAGS+=	--jitter-srcdir=${WRKSRC}/jitter

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
