# $NetBSD: Makefile,v 1.1.1.1 2008/02/15 20:13:11 asau Exp $

DISTNAME=		gforth-0.6.9-20070604
#PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://www.complang.tuwien.ac.at/forth/gforth/Snapshots/

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://www.complang.tuwien.ac.at/forth/gforth/
COMMENT=		Fast interpreter for the Forth language

ONLY_FOR_PLATFORM=	*-*-alpha *-*-i386 *-*-m68k *-*-powerpc *-*-sparc

GNU_CONFIGURE=		YES
PKG_DESTDIR_SUPPORT=	user-destdir

# Make sure elisp will be installed even if no emacs installed.
CONFIGURE_ENV+=		EMACS=${PREFIX}/bin/emacs
CFLAGS+=		-Dunix
INFO_FILES=		# PLIST
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			infodir=${PREFIX:Q}/${PKGINFODIR:Q}		\
			mandir=${PREFIX:Q}/${PKGMANDIR:Q}

TEST_TARGET=	test

# Kernel image filename is arch dependent
KERNEL_FI_cmd=								\
	if ${TEST} ! -f ${WRKSRC}/Makefile; then			\
		${ECHO} "__nonexistent__";				\
		exit 0;							\
	fi;								\
	cd ${WRKSRC} &&							\
	{ ${ECHO} 'prkern:';						\
	  ${ECHO} '	@${ECHO} $$(kernel_fi)';			\
	  ${ECHO} ;							\
	  ${CAT} Makefile; } | ${MAKE_PROGRAM} -f - prkern
PLIST_SUBST+=	KERNEL_FI=${KERNEL_FI_cmd:sh:Q}

# XXX Need test.
#.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/ffcall/buildlink3.mk"

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
