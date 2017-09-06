# $NetBSD: Makefile,v 1.3 2012/10/07 16:45:13 asau Exp $

PKGNAME=	texlive-texmf-minimal-${TEXLIVE_VERSION}
DISTNAME=	texlive_texmf-minimal-${TEXLIVE_VERSION}${TEXLIVE_GENERATION}
CATEGORIES=	print
MASTER_SITES=	http://students.dec.bournemouth.ac.uk/ebarrett/texlive/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	TeXLive texmf, minimal version from Edd Barret's OpenBSD repository

PKG_DESTDIR_SUPPORT=	destdir

NO_BUILD=	yes

USE_TOOLS+=	chown

# Is this necessary?
SUBST_CLASSES+=		fmtutil
SUBST_MESSAGE.fmtutil=	Tweaking fmtutil.cnf
SUBST_STAGE.fmtutil=	post-patch
SUBST_FILES.fmtutil=	texmf/web2c/fmtutil.cnf
SUBST_SED.fmtutil=	-e "s,.*xetex.*,,g"

pre-install:
	rm -Rf ${WRKSRC}/texmf/doc/man
	rm -Rf ${WRKSRC}/texmf-dist/source
	# fix for broken bbold font
	rm -f ${WRKSRC}/texmf-dist/tex/latex/jknapltx/ubbold.fd
	cd ${WRKSRC}/texmf-dist/tex/latex/bbold/ && mv -f Ubbold.fd ubbold.fd

do-install:
	cp -R ${WRKSRC}/texmf ${DESTDIR}${PREFIX}/share
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/texmf
	cp -R ${WRKSRC}/texmf-dist ${DESTDIR}${PREFIX}/share
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/texmf-dist

.include "../../wip/texlive/Makefile.common"

.include "../../mk/bsd.pkg.mk"
