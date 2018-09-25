# $NetBSD$

DISTNAME=	posh_0.13.1
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/posh/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.debian.org/posh
COMMENT=	Debian Policy-compliant Ordinary SHell
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c99
USE_TOOLS+=	perl autoconf automake
GNU_CONFIGURE=	YES

PKG_SHELL=		bin/posh
WRKSRC=			${WRKDIR}/posh
INSTALLATION_DIRS=	share/doc/posh

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

# On GNU based systems only: Use GNU getopt() as written by Debian
# This Debian code leads to undefined behaviour with POSIX getopt()
# On NetBSD e.g. "command -v ls" enters an infinite loop and eats up all memory
.if ${OPSYS} == "Linux" || ${OPSYS} == "GNUkFreeBSD"
CFLAGS+=	-DPKGSRC_GNU_GETOPT=1
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf

post-install:
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${DESTDIR}${PREFIX}/share/doc/posh

.include "../../mk/bsd.pkg.mk"
