# $NetBSD$

DISTNAME=	divecmd-0.1.2
CATEGORIES=	misc
MASTER_SITES=	https://kristaps.bsd.lv/divecmd/snapshots/

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://kristaps.bsd.lv/divecmd/
COMMENT=	Download and process dive computer data
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	BINDIR="${BINDIR}"
CONFIGURE_ARGS+=	CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=	DESTDIR="${DESTDIR}"
CONFIGURE_ARGS+=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	LIBDIR="${LIBDIR}"
CONFIGURE_ARGS+=	MANDIR="${PREFIX}/${PKGMANDIR}"
CONFIGURE_ARGS+=	PREFIX="${PREFIX}"
CONFIGURE_ARGS+=	SBINDIR="${SBINDIR}"

.include "../../wip/libdivecomputer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
