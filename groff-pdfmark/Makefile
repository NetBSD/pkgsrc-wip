# $NetBSD$

DISTNAME=	groff-pdfmark-20261029.1
PKGNAME=	groff-pdfmark-26.10
CATEGORIES=	textproc
MASTER_SITES=	https://download.savannah.gnu.org/releases/groff-pdfmark/
EXTRACT_SUFX=	-src.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/groff-pdfmark/
COMMENT=	PDF publishing macros and pdfroff driver for GNU troff
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/groff-pdfmark-26.10

USE_TOOLS+=	sed
NO_CONFIGURE=	yes

# Runtime requirements
DEPENDS+=	groff-[0-9]*:../../textproc/groff
DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript

# All man pages shipped by the independent project
MAN1=		pdfroff.1
MAN7=		pdfroff.7 \
		groff_pdfmark.7 \
		groff_pdfhref.7 \
		groff_pdfnote.7 \
		groff_mspdf.7 \
		groff_omit.7 \
		groff_opmode.7 \
		groff_sanitize.7 \
		groff_toc.7

# Macro packages to site-tmac only
TMAC_FILES=	pdfmark.tmac spdf.tmac omit.tmac opmode.tmac \
		sanitize.tmac pdfroff.tmac strcase.tmac newpage.tmac \
		float.tmac redirect.tmac appendix.tmac anpdf.tmac \
		toc-base.tmac toc-class.tmac spdf-toc.tmac fdl-setup.tmac

INSTALLATION_DIRS=	bin \
			${PKGMANDIR}/man1 ${PKGMANDIR}/man7 \
			share/groff/site-tmac \
			share/examples/groff-pdfmark \
			share/examples/groff-pdfmark/artwork \
			share/doc/groff-pdfmark

# Generate man pages the same way the old groff build did:
do-build:
.for f in ${MAN1} ${MAN7}
	${SED} \
	    -e 's|@MAN1EXT@|1|g' \
	    -e 's|@MAN7EXT@|7|g' \
	    -e 's|@VERSION@|${PKGVERSION}|g' \
	    -e 's|@MDATE@|${PKGVERSION}|g' \
	    -e 's|@SITE_TMACDIR@|${PREFIX}/share/groff/site-tmac|g' \
	    -e 's|@PDFDOCDIR@|${PREFIX}/share/doc/groff-pdfmark|g' \
	    -e 's|@AUTHOR_MT_ADDRESS@|keith.d.marshall@ntlworld.com|g' \
	    -e 's|@PROJECT_HOSTING_SITE@|https://savannah.nongnu.org/projects/groff-pdfmark/|g' \
	    -e '/@IMPORT_LOCAL_FALLBACK_MACROS@/d' \
	    -e '/@ENUMERATE_MR_REFERENCES@/d' \
	    ${WRKSRC}/man/${f}.man > ${WRKDIR}/${f}
.endfor
	# pdfroff script - update the version
	${SED} -e 's|@VERSION@|${PKGVERSION}|g' \
	    ${WRKSRC}/pdfroff.sh > ${WRKDIR}/pdfroff
	${CHMOD} +x ${WRKDIR}/pdfroff

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pdfroff ${DESTDIR}${PREFIX}/bin/pdfroff

.for f in ${TMAC_FILES}
	${INSTALL_DATA} ${WRKSRC}/tmac/${f} \
		${DESTDIR}${PREFIX}/share/groff/site-tmac/
.endfor

.for f in ${MAN1}
	${INSTALL_MAN} ${WRKDIR}/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${f}
.endfor
.for f in ${MAN7}
	${INSTALL_MAN} ${WRKDIR}/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/${f}
.endfor

	# Example sources so users can rebuild the reference document
	${INSTALL_DATA} ${WRKSRC}/pdfmark.ms \
		${DESTDIR}${PREFIX}/share/examples/groff-pdfmark/
	${INSTALL_DATA} ${WRKSRC}/cover.ms \
		${DESTDIR}${PREFIX}/share/examples/groff-pdfmark/
	${INSTALL_DATA} ${WRKSRC}/cover-info.ms \
		${DESTDIR}${PREFIX}/share/examples/groff-pdfmark/
	${INSTALL_DATA} ${WRKSRC}/fdl-typesetting.ms \
		${DESTDIR}${PREFIX}/share/examples/groff-pdfmark/
	${INSTALL_DATA} ${WRKSRC}/artwork/gnu.eps \
		${DESTDIR}${PREFIX}/share/examples/groff-pdfmark/artwork/

	${INSTALL_DATA} ${WRKSRC}/ChangeLog \
		${DESTDIR}${PREFIX}/share/doc/groff-pdfmark/
	${INSTALL_DATA} ${WRKSRC}/gpl-v3.0.txt \
		${DESTDIR}${PREFIX}/share/doc/groff-pdfmark/

.include "../../mk/bsd.pkg.mk"
