# $NetBSD: Makefile,v 1.1.1.1 2012/04/22 18:59:46 cmfuhrman Exp $

DISTNAME=	svninfo-0.7.4
PKGNAME=        tex-svninfo-doc-0.7.4
CATEGORIES=	print
MASTER_SITES=	http://www.brucker.ch/projects/svninfo/download/

MAINTAINER=	cfuhrman@panix.com
HOMEPAGE=	http://www.brucker.ch/projects/svninfo/
COMMENT=	Documention for tex-svninfo
LICENSE=        lppl-1.3c

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

USE_TOOLS+=     gmake
NO_CONFIGURE=   yes
BUILD_TARGET=   sty pdf ps

DEPENDS+=       tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+= dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+= makeindexk-[0-9]*:../../textproc/makeindexk

INSTALLATION_DIRS= share/texmf-dist/doc/latex/svninfo

do-install:
	${INSTALL_DATA} ${WRKSRC}/README \
	        ${WRKSRC}/svninfo.init   \
		${WRKSRC}/svninfo.pdf    \
		${WRKSRC}/svninfo.ps     \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/latex/svninfo

.include "../../mk/bsd.pkg.mk"
