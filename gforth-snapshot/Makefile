# $NetBSD: Makefile,v 1.50 2022/06/28 11:34:11 wiz Exp $

DISTNAME=		gforth
PKGNAME=		gforth-0.7.9pre20250321
CATEGORIES=		lang
#MASTER_SITES=		${MASTER_SITE_GNU:=gforth/}
#MASTER_SITES+=		https://git.savannah.gnu.org/cgit/gforth.git/snapshot/
MASTER_SITES+=		https://www.complang.tuwien.ac.at/forth/gforth/Snapshots/current/
DIST_SUBDIR=		gforth-${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		https://www.complang.tuwien.ac.at/forth/gforth/
COMMENT=		Fast interpreter for the Forth language
LICENSE=		gnu-gpl-v3

# This package claims to specifically support the following arches:
#    alpha arm hppa i386 ia64 m68k mips powerpc sparc x86_64
# and it has a generic config that should work for all random other
# processors as long as they have IEEE floats. So, we'll explicitly
# exclude vax and allow anything else.
NOT_FOR_PLATFORM=	*-*-vax

WRKSRC=			${WRKDIR}/gforth-${PKGVERSION_NOREV:S/pre/_/}

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes
USE_TOOLS+=		gmake m4 makeinfo gzip perl:build
TEXINFO_REQD+=		7.0
TEST_TARGET=		check

CONFIGURE_ARGS+=	EMACS=""

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libffcall/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
