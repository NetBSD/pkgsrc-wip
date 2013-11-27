# $NetBSD: Makefile,v 1.7 2013/11/27 04:12:35 makoto Exp $

DISTNAME=		lldpd-0.7.7
CATEGORIES=		net
MASTER_SITES=		http://media.luffy.cx/files/lldpd/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vincentbernat.github.com/lldpd/
COMMENT=		802.1ab (LLDP) implementation
LICENSE=		isc
# `lldpcli` will be linked to GNU Readline (which is GPL licensed)
# if available. To avoid this, use `--without-readline` as a configure
# option.

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-privsep-chroot=${PKG_HOME._lldpd}
BUILD_DEFS+=		VARBASE

# to find -lperl, should be portable and simpler, please correct
.include "../../mk/bsd.prefs.mk"
# This PATH is sometimes defined with SITEARCHEXP
LDFLAGS+=		-L${PREFIX}/lib/perl5/5.18.0/${MACHINE_ARCH}-${OPSYS:tl}-thread-multi/CORE

# ERROR: sbin/lldpd: missing library: libperl.so
# both COMPILER_RPATH_FLAG LINKER_RPATH_FLAG doesn't make it.
LDFLAGS+=		-Wl,-R${PREFIX}/lib/perl5/5.18.0/${MACHINE_ARCH}-${OPSYS:tl}-thread-multi/CORE
RCD_SCRIPTS=		lldpd
PKG_GROUPS=		_lldpd
PKG_USERS=		_lldpd:_lldpd
PKG_HOME._lldpd=	${VARBASE}/chroot/lldpd

OWN_DIRS=		${VARBASE}/chroot/lldpd
AUTO_MKDIRS=		yes

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

.include "options.mk"

BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.5
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
