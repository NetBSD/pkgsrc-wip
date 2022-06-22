# $NetBSD$

DISTNAME=	983d44d72ca4def1c26ef74f69543313e3176b31
PKGNAME=	got-portable-${PKGVER}
PKGVER=		0.70
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://repo.or.cz/got-portable.git/snapshot/

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://gameoftrees.org/
COMMENT=	Game of Trees version control system manipulating Git repo
LICENSE=	isc

CONFLICTS+=		got-[0-9]*

USE_TOOLS+=		pkg-config autoconf automake autoreconf
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin libexec ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

WRKSRC=	${WRKDIR}/got-portable-983d44d

.include "../../mk/bsd.prefs.mk"

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

post-patch:
.if ${OPSYS} == "NetBSD"
	# NetBSD has sha1.h.
	${RM} -f ${WRKSRC}/openbsd-compat/sha1.h
.endif

.if ${OPSYS} == "Linux"
# compatibility macros and functions for Linux.
.include "../../devel/libbsd/buildlink3.mk"
.include "../../wip/libmd/buildlink3.mk"
.endif

# For set_panel_userptr(3)'s second argument and waddwstr(3).
.include "../../devel/ncursesw/buildlink3.mk"

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
