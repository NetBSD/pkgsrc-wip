# $NetBSD$

DISTNAME=	pacman-5.2.2
CATEGORIES=	pkgtools
MASTER_SITES=	https://sources.archlinux.org/other/pacman/

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://www.archlinux.org/pacman/
COMMENT=	Simple library-based package manager
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_TOOLS+=		perl
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	lib/libalpm/libalpm.pc.in

EGDIR=	${PREFIX}/share/examples/pacman

CONF_FILES=	${EGDIR}/pacman.conf ${PKG_SYSCONFDIR}/pacman.conf \
		${EGDIR}/makepkg.conf ${PKG_SYSCONFDIR}/makepkg.conf

INSTALLATION_DIRS=	share/bash-completion/completions

post-install:
	${MKDIR} -p ${DESTDIR}${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/etc/pacman.conf ${DESTDIR}${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/etc/makepkg.conf ${DESTDIR}${EGDIR}

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
