# $NetBSD$

DISTNAME=	posh_0.13.1
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/posh/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.debian.org/posh
COMMENT=	Debian Policy-compliant Ordinary SHell
# Gnulib is V3 and the Debian parts are "V2 or later" => Use V3 for all parts
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c99
USE_TOOLS+=	perl autoconf automake
GNU_CONFIGURE=	YES

PKG_SHELL=		bin/posh
WRKSRC=			${WRKDIR}/posh
INSTALLATION_DIRS=	share/doc/posh

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

# posh doesn't work with POSIX getopt!
# This adds the "getopt-gnu" module of gnulib
# The utility "tempfile" (required by testsuite) is taken from debianutils
post-extract:
	${CP} -R -P ${FILESDIR}/gnulib_getopt-gnu/* ${WRKSRC}
	${MKDIR} ${WRKSRC}/debianutils
	${CP} ${FILESDIR}/debianutils_tempfile/tempfile.c ${WRKSRC}/debianutils

pre-configure:
	cd ${WRKSRC} ; autoreconf -fi

post-install:
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${DESTDIR}${PREFIX}/share/doc/posh
	${RM} ${DESTDIR}${PREFIX}/bin/tempfile

.include "../../mk/bsd.pkg.mk"
