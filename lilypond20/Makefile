# $NetBSD: Makefile,v 1.5 2003/10/27 03:41:19 atamaniuk Exp $
# created 2003-10-22 Patrick Atamaniuk <atamaniuk-pkgsrc@frobs.net>
# MAINTAINER_of-previous-lilypond-versions=	rh@NetBSD.org

DISTNAME=	lilypond-2.0.1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lilypond.org/pub/LilyPond/v2.0/

MAINTAINER=	atamaniuk-ports@frobs.net
HOMEPAGE=	http://lilypond.org/web/
COMMENT=	GNU Music Typesetter

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_PKGINSTALL=		YES
MAKEFILE=		GNUmakefile

GCC_REQD=	3.0.5
USE_MAKEINFO=	YES
TEXINFO_REQD=	4.0
INFO_FILES=	lilypond.info lilypond-internals.info music-glossary.info

INSTALL_EXTRA_TMPL+=      ${.CURDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=      ${.CURDIR}/DEINSTALL
FILES_SUBST+=           PKGVERSION=${PKGVERSION}

PYTHON_VERSIONS_ACCEPTED= 20 21 21pth 22 22pth 23 23pth
CPPFLAGS+=	-I${WRKSRC}/lily/out -D__GNU_LIBRARY__

CONFIGURE_ARGS+=--disable-optimising
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}

EXAMPLES_DIR=	${PREFIX}/share/examples/${DISTNAME}
MESSAGE_SUBST+=EXAMPLES_DIR=${EXAMPLES_DIR}
DOCSDIR?=	${PREFIX}/doc/${DISTNAME}
CPIO?=/usr/bin/cpio

pre-configure:
	@ ${SETENV} WRKSRC=${WRKSRC} ${FILESDIR}/pre-configure
post-configure:
	@ ${SETENV} WRKSRC=${WRKSRC} ${FILESDIR}/post-configure

post-install:
	@ ${ECHO} Installing examples to ${EXAMPLES_DIR}
	${INSTALL_DATA_DIR} ${EXAMPLES_DIR}
	@- cd ${WRKSRC} && ${FIND} input \! -path */CVS\* -and \! -path \*/out\* -and \! -name GNUmakefile -print0 \
		| ${CPIO} -p0 ${EXAMPLES_DIR}
	${INSTALL_SCRIPT_DIR} ${EXAMPLES_DIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/buildscripts/out/lilypond-login ${EXAMPLES_DIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/buildscripts/out/lilypond-profile ${EXAMPLES_DIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/lilypond.vim ${EXAMPLES_DIR}/scripts

	${INSTALL_DATA_DIR} ${DOCSDIR}
.for f in AUTHORS.txt INSTALL.txt NEWS.txt    README.txt
	${INSTALL_DATA} ${WRKSRC}/Documentation/topdocs/out/${f} ${DOCSDIR}
.endfor

.include "../../wip/mftrace/buildlink2.mk"
.include "../../lang/guile/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../print/teTeX2-bin/kpathsea.buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
