# $NetBSD$

DISTNAME=	0.24.2
PKGNAME=	hare-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	https://git.sr.ht/~sircmpwn/hare/archive/
DIST_SUBDIR=	hare

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://harelang.org/
COMMENT=	The Hare programming language
LICENSE=	gnu-gpl-v3 AND mpl-2.0

WRKSRC=		${WRKDIR}/hare-${DISTNAME}

USE_TOOLS+=	gmake

TOOL_DEPENDS+=	binutils>=2.41:../../devel/binutils
TOOL_DEPENDS+=	scdoc>=1.10.0:../../textproc/scdoc
DEPENDS+=	harec>=${DISTNAME}:../../wip/harec

TEST_TARGET=		check
MAKE_FLAGS+=		LD=gld
MAKE_FLAGS+=		OPSYS=${OPSYS:tl}

pre-configure:
	cp ${FILESDIR}/config.mk ${WRKSRC}

# TODO: After NetBSD 10.1, we can remove the time/chrono patch and the
#       following
MASTER_SITES+=	https://data.iana.org/time-zones/code/
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	leap-seconds.list
pre-build:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/hare
	${INSTALL_DATA} ${WRKDIR}/leap-seconds.list \
		${DESTDIR}${PREFIX}/share/hare/leap-seconds.list

.include "../../mk/bsd.pkg.mk"
