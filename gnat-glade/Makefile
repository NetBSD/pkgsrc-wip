# $NetBSD: Makefile,v 1.0 2024/12/05 14:00:00 dkazankov Exp $

#DISTNAME=	${PKG_DISTNAME}
DISTNAME=	gnat-glade-${PKGVERSION_NOREV}
PKGNAME=	gnat-glade-6.0.1
CATEGORIES=	devel
# Original sourceforge site periodically loses the snapshot,
# so we use github clone
MASTER_SITES=	${MASTER_SITE_GITHUB:=dkazankov/}
GITHUB_PROJECT=	gnat-glade
GITHUB_TAG=	v${PKGVERSION_NOREV}
#DISTFILES=	${PKG_DISTNAME}.zip
#SITES.${PKG_DISTNAME}.zip=	-https://sourceforge.net/code-snapshots/svn/g/gn/gnat-glade/code/${PKG_DISTNAME}.zip

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/gnat-glade/
COMMENT=	GNAT Library for Ada Distributed Environment
LICENSE=	gnu-gpl-v2

#PKG_DISTNAME=	gnat-glade-code-r135-trunk

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CHECK_PIE_SKIP+=	bin/*
CHECK_RELRO_SKIP+=	bin/*

USE_LANGUAGES=	c ada
# This component now throws an error when compiled with GNAT 6 or 10
GCC_REQD+=	13

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=			replace-shell
SUBST_MESSAGE.replace-shell=	Replace shell in ${SUBST_FILES.replace-shell}
SUBST_STAGE.replace-shell=	pre-configure
SUBST_FILES.replace-shell=	Dist/gnatdist-config.in
SUBST_VARS.replace-shell=	SHELL

post-patch:
	chmod +x ${WRKSRC}/Dist/config.sdefault

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin include lib \( -type f -or -type l \) -print | ${SORT};

.include "../../mk/bsd.pkg.mk"
