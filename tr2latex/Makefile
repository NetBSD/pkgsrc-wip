# $NetBSD: Makefile,v 1.2 2004/12/02 16:39:08 thomasklausner Exp $

DISTNAME=	tr2latex
PKGNAME=	${DISTNAME}-2.2
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
MAKEFILE=	Makefile.unix
BUILD_TARGET=	tr2latex
PKGMANDIR?=	man  # until in pkgsrc
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/texmf/tex/latex/misc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tr2latex ${PREFIX}/bin/tr2latex
	${INSTALL_MAN} ${WRKSRC}/tr2latex.man ${PREFIX}/${PKGMANDIR}/man1/tr2latex.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/tex/latex/misc
	${INSTALL_DATA} ${WRKSRC}/troffman.sty ${PREFIX}/share/texmf/tex/latex/misc/
	${INSTALL_DATA} ${WRKSRC}/troffms.sty ${PREFIX}/share/texmf/tex/latex/misc/

.include "../../mk/bsd.pkg.mk"
