# $NetBSD$

DISTNAME=	cc65-2.17
CATEGORIES=	cross lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=cc65/}
GITHUB_PROJECT=	cc65
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cc65.org/
COMMENT=	C cross compiler for 6502 target systems
LICENSE=	zlib

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake perl
REPLACE_PERL=	util/ca65html

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX} DESTDIR=${DESTDIR}${PREFIX}

SUBST_CLASSES+=		perl
SUBST_MESSAGE.perl=	Fixing the path of perl.
SUBST_STAGE.perl=	pre-configure
SUBST_FILES.perl=	src/ca65/macpack/cvt-mac.pl src/ld65/cfg/cvt-cfg.pl
SUBST_SED.perl=		-e "s,/usr/bin/perl,${PREFIX}/bin/perl,g"

.include "../../mk/bsd.pkg.mk"
