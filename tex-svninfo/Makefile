# $NetBSD: Makefile,v 1.1.1.1 2012/04/22 18:54:01 cmfuhrman Exp $

DISTNAME=	svninfo-0.7.4
PKGNAME=        tex-${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	http://www.brucker.ch/projects/svninfo/download/

MAINTAINER=	cfuhrman@panix.com
HOMEPAGE=	http://www.brucker.ch/projects/svninfo/
COMMENT=	Support for the subversion revision control system
LICENSE=	lppl-1.3c

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

USE_TOOLS+=     gmake
NO_CONFIGURE=   yes
BUILD_TARGET=   sty

DEPENDS+=       tex-latex-bin-[0-9]*:../../print/tex-latex-bin

INSTALLATION_DIRS= share/texmf-dist/tex/latex/svninfo

.if empty(TEX_TEXMF_DIRS) || ${TEX_TEXMF_DIRS} != "none"
.  include "../../print/kpathsea/texmf.mk"
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/svninfo.cfg \
	        ${WRKSRC}/svninfo.sty \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/svninfo

.include "../../mk/bsd.pkg.mk"
