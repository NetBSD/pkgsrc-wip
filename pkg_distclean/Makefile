# $NetBSD: Makefile,v 1.1.1.1 2003/07/19 01:12:32 bubuchka Exp $

DISTNAME=	pkg_distclean-0.1
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	mishka@terabyte.com.ua
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Removes old/unattended/unknown files from DISTFILES directory

EXTRACT_ONLY=	# empty
NO_CHECKSUM=    yes
NO_BUILD=	yes
NO_MTREE=	yes

# Set SCRIPT_SUBST to substitute "@VARIABLE@" with "value"
SCRIPT_SUBST+=	AWK=${AWK:Q}				\
		CAT=${CAT:Q}				\
		DIFF=diff				\
		ECHO=${ECHO:Q}				\
		FIND=${FIND:Q}				\
		GREP=${GREP:Q}				\
		LS=${LS:Q}				\
		MAKE=${MAKE:Q}				\
		RM=${RM:Q}				\
		SED=${SED:Q}				\
		SH=${SH:Q}				\
		SORT=${SORT:Q}				\
		XARGS=${XARGS:Q}			\
		DISTDIR=${DISTDIR:Q}			\
		PKG_TOOLS_BIN=${PKG_TOOLS_BIN:Q}	\
		PREFIX=${PREFIX:Q}			\
		_PKGSRCDIR=${_PKGSRCDIR:Q}

SCRIPT_SUBST_SED=	${SCRIPT_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

do-configure:
		${SED} ${SCRIPT_SUBST_SED}		\
			< ${FILESDIR}/pkg_distclean	\
			> ${WRKSRC}/pkg_distclean

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/pkg_distclean ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
