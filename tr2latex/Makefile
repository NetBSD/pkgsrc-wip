# $NetBSD: Makefile,v 1.5 2013/11/13 18:44:23 minskim Exp $

DISTNAME=	tr2latex
PKGNAME=	${DISTNAME}-2.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=support/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	ftp://ctan.tug.org/tex-archive/support/tr2latex/README
COMMENT=	Troff to LaTeX converter

DIST_SUBDIR=	${PKGNAME_NOREV}
# the download servers archive this on the fly

# todo: restricted because of "no profit is made by copying the files"
# see README

# probably should make a tarball for this
# different ctan servers send slightly different files
# checksum can't be used and since there are various
# ctan servers one could give compromised files.
# and some of the mirrors don't tar it up.
# also tar ball has windows executable?

# todo: maybe patch Makefile.unix for CC and CFLAGS not overwritten
MAKE_FILE=		Makefile.unix
BUILD_TARGET=		tr2latex
PKGMANDIR?=		man  # until in pkgsrc
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/texmf-dist/tex/latex/misc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tr2latex ${DESTDIR}${PREFIX}/bin/tr2latex
	${INSTALL_MAN} ${WRKSRC}/tr2latex.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tr2latex.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/misc
	${INSTALL_DATA} ${WRKSRC}/troffman.sty ${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/misc/
	${INSTALL_DATA} ${WRKSRC}/troffms.sty ${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/misc/

.include "../../mk/bsd.pkg.mk"
