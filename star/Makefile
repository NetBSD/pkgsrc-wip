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

.include "../../mk/bsd.prefs.mk"

# Shared platform specific code for schilytools (provided by smake package)
.include "../../wip/smake/Makefile.common"

do-configure:
	cd ${WRKSRC}/inc && ${SMAKE}

do-build:
	cd ${WRKSRC} && for library in					\
		libschily libdeflt libfind librmt;			\
	do								\
		cd ${WRKSRC}/$${library} && ${SMAKE};			\
	done
	cd ${WRKSRC}/star && ${SMAKE}

# Process tables in manpage
post-build:
	cd ${WRKSRC} && ${TBL} star/spax.1 >star/spax.1.tmp &&		\
		${MV} -f star/spax.1.tmp star/spax.1
	cd ${WRKSRC} && ${TBL} star/star.4 >star/star.4.tmp &&		\
		${MV} -f star/star.4.tmp star/star.4

do-test:
	cd ${WRKSRC}/star &&						\
		cd tests; ${SMAKE} tests

# Documentation is in ${WRKSRC}/README.compile
do-install:
	cd ${WRKSRC}/star && ${SMAKE}					\
		INS_BASE=${PREFIX} DEFMANBASE=. DESTDIR=${DESTDIR} install

.include "../../mk/bsd.pkg.mk"
