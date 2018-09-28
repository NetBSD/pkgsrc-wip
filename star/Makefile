# $NetBSD$

DISTNAME=	schily-2018-09-26
PKGNAME=	star-1.5.4
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schilytools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://s-tar.sf.net/
COMMENT=	Unique standard tape archiver
LICENSE=	cddl-1.0

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	tbl
TOOL_DEPENDS+=	smake-[0-9]*:../../wip/smake
SMAKE=		MAKEFLAGS= smake
MAKE_FLAGS+=	DESTDIR=${DESTDIR} INS_BASE=${PREFIX} DEFMANBASE=. MANDIR=${PKGMANDIR}

# This creates strange "shift: can't shift that many" errors
#MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/default/star 0755
CONF_FILES=	${PREFIX}/share/examples/star/star ${PKG_SYSCONFDIR}/default/star
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

# Shared platform specific code for schilytools (provided by smake package)
.include "../../wip/smake/Makefile.common"

do-configure:
	cd ${WRKSRC}/inc && ${SMAKE} ${MAKE_FLAGS}

do-build:
	cd ${WRKSRC} && for library in					\
		libschily libdeflt libfind librmt;			\
	do								\
		cd ${WRKSRC}/$${library} && ${SMAKE} ${MAKE_FLAGS};	\
	done
	cd ${WRKSRC}/star && ${SMAKE} ${MAKE_FLAGS}

# Process tables in manpage
post-build:
	cd ${WRKSRC} && if ! ${TEST} -f star/pkgsrc_tbl.done; then	\
		${TBL} star/spax.1 >star/spax.1.tmp &&			\
		${MV} -f star/spax.1.tmp star/spax.1 &&			\
		${TBL} star/star.4 >star/star.4.tmp &&			\
		${MV} -f star/star.4.tmp star/star.4 &&			\
		${TOUCH} star/pkgsrc_tbl.done;				\
	fi

do-test:
	cd ${WRKSRC}/star && cd tests ; ${SMAKE} ${MAKE_FLAGS} tests

do-install:
	cd ${WRKSRC}/star && ${SMAKE} ${MAKE_FLAGS} install
	${INSTALL_DATA} ${WRKSRC}/star/star.dfl				\
		${DESTDIR}${PREFIX}/share/examples/star/star

.include "../../mk/bsd.pkg.mk"
