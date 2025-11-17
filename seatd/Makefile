# $NetBSD$

DISTNAME=	seatd-0.9.1
CATEGORIES=	sysutils
MASTER_SITES=	https://git.sr.ht/~kennylevinsen/seatd/archive/
DISTFILES=	${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://git.sr.ht/~kennylevinsen/seatd/
COMMENT=	Seat management daemon and library
LICENSE=	mit

#USE_TOOLS+=	pkg-config
TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

MESON_ARGS+=	-Dlibseat-logind=disabled
MESON_ARGS+=	-Dlibseat-builtin=enabled

SPECIAL_PERMS+=	bin/seatd-launch ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	scdoc < ${WRKSRC}/man/seatd.1.scd > ${WRKSRC}/man/seatd.1
	scdoc < ${WRKSRC}/man/seatd-launch.1.scd > ${WRKSRC}/man/seatd-launch.1
	${INSTALL_MAN} ${WRKSRC}/man/seatd.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/seatd.1
	${INSTALL_MAN} ${WRKSRC}/man/seatd-launch.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/seatd-launch.1

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
