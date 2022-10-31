# $NetBSD$

DISTNAME=	e6ef48a9d4e506755058cf8aadafaf6820228e17
PKGNAME=	got-portable-${PKGVER}
PKGVER=		0.77
CATEGORIES=	devel
MASTER_SITES=	https://repo.or.cz/got-portable.git/snapshot/

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://gameoftrees.org/
COMMENT=	Game of Trees version control system manipulating Git repo
LICENSE=	isc

CONFLICTS+=		got-[0-9]*

ONLY_FOR_PLATFORM+=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	Darwin-*-*
ONLY_FOR_PLATFORM+=	Linux-*-*
ONLY_FOR_PLATFORM+=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-*

USE_TOOLS+=		pkg-config autoconf automake autoreconf
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin libexec ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

shortdist=	"`${ECHO} ${DISTNAME} | ${CUT} -c 1-7`"
WRKSRC=		${WRKDIR}/got-portable-${shortdist}

.include "../../mk/bsd.prefs.mk"

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

.if ${OPSYS} == "Linux"
# compatibility macros and functions for Linux.
.include "../../devel/libbsd/buildlink3.mk"
.include "../../devel/libmd/buildlink3.mk"
.endif

.if ${OPSYS} == "Darwin"
# define uuid library to use
.include "../../devel/ossp-uuid/buildlink3.mk"
.else
.include "../../devel/libuuid/buildlink3.mk"
.endif

# need libcrypto.so.1.1
BUILDLINK_API_DEPENDS.openssl+=   openssl>=1.1.1
.include "../../security/openssl/buildlink3.mk"

# required for set_panel_userptr(3) and waddwstr(3).
.include "../../devel/ncursesw/buildlink3.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
