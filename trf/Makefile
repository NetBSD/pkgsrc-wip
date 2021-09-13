# $NetBSD$

GITHUB_PROJECT=	TRF
GITHUB_TAG=	refs/tags/v4.09.1
DISTNAME=	v4.09.1
# PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
PKGNAME=	${GITHUB_PROJECT:tl}-4.09.1.20210623
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=Benson-Genomics-Lab/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tandem.bu.edu/trf/trf.html
COMMENT=	Genome tandom repeats finder
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/TRF-4.09.1
GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c

# XXX - this package installs version-specific links to the main
# executable.  However, despite the DISTNAME and the links on github,
# the code itself has a different version (i.e., 4.10.0-rc.2 not
# 4.09.1), which makes handling this awkward.  Besides, this distfile
# appears to be a release candidate not a release, again despite the
# information upstream.  For the time being, just ignore this file
# altogether, but leave most of the infrastructure in place for the
# future, just in case.
#
.include "../../mk/bsd.prefs.mk"

# TODO - handle other OSes
PLIST_VARS+=	Darwin
.if ${OPSYS} == "Darwin"
# PLIST.Darwin=	yes	# TODO - uncomment when versions are fixed upstream
.endif

# TODO - remove this when the versions get sorted out upstream
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/trf*.exe

.include "../../mk/bsd.pkg.mk"
