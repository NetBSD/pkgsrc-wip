# $NetBSD: Makefile,v 1.50 2022/06/28 11:34:11 wiz Exp $

DISTNAME=		gforth
PKGNAME=		gforth-0.7.9pre20250319
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

#MAKE_JOBS_SAFE=		no # fresh Gforth is required to build doc
#BUILD_TARGET=		all info # doc
TEST_TARGET=		check

#CFLAGS+=		-Dunix
#INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
#			infodir=${PREFIX:Q}/${PKGINFODIR:Q}		\
#			mandir=${PREFIX:Q}/${PKGMANDIR:Q}

#INSTALLATION_DIRS=	share/emacs/site-lisp

# Kernel image filename is arch dependent
#KERNEL_FI_cmd=								\
#	if ${TEST} ! -f ${WRKSRC}/Makefile; then			\
#		${ECHO} "__nonexistent__";				\
#		exit 0;							\
#	fi;								\
#	cd ${WRKSRC} &&							\
#	{ ${ECHO} 'prkern:';						\
#	  ${ECHO} '	@${ECHO} $$(kernel_fi)';			\
#	  ${ECHO} ;							\
#	  ${CAT} Makefile; } | ${MAKE_PROGRAM} -f - prkern
#PLIST_SUBST+=	KERNEL_FI=${KERNEL_FI_cmd:sh:Q}

# XXX Need test.
#.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libffcall/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
