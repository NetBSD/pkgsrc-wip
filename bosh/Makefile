# $NetBSD$

DISTNAME=	schily-2018-09-04
PKGNAME=	${DISTNAME:S/schily/bosh/}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schilytools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://schilytools.sourceforge.net/bosh.html
COMMENT=	The Schily Bourne Shell
LICENSE=	cddl-1.0

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	smake tbl

PKG_SHELL=	bin/bosh
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

# Fix testsuite (NetBSD od creates whitespace at the end of output lines)
SUBST_CLASSES+=		od
SUBST_STAGE.od=		post-patch
SUBST_FILES.od=		sh/tests/shelltests/printf/printf.sh
SUBST_SED.od=		-e "s,-e \\\\\"s/\^\[ 	]\*//\\\[\"],-e \\\\\"s/^[ 	]*//\\\\\" -e \\\\\"s/[ 	]*$$//\\\\\",g"
SUBST_MESSAGE.od=	Fix processing of output from od.

# Shared platform specific hacks for schilytools (provided by smake package)
.include "../../wip/smake/Makefile.common"

do-configure:
	cd ${WRKSRC}/inc && MAKEFLAGS=${MAKEFLAGS:S/:_MAKE/_PKGSRC_MAKE/} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-build:
	cd ${WRKSRC} && for library in					\
		libschily libxtermcap libfind libgetopt libshedit;	\
	do								\
		cd ${WRKSRC}/$${library} &&				\
			${MAKE_PROGRAM} ${MAKE_FLAGS};			\
	done
	cd ${WRKSRC}/sh && ${MAKE_PROGRAM} ${MAKE_FLAGS}

# Process tables in manpage
post-build:
	cd ${WRKSRC} && ${TBL} sh/sh.1 >sh/sh.1.tmp;			\
		mv -f sh/sh.1.tmp sh/bosh.1

do-test:
	cd ${WRKSRC}/sh &&						\
		cd tests; ${MAKE_PROGRAM} ${MAKE_FLAGS} tests

do-install:
	cd ${WRKSRC}/sh &&						\
		${INSTALL_PROGRAM} ${WRKSRC}/sh/OBJ/*/sh		\
			${DESTDIR}${PREFIX}/bin/bosh;			\
		${INSTALL_MAN} ${WRKSRC}/sh/bosh.1 			\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;		\

.include "../../mk/bsd.pkg.mk"
