# $NetBSD$

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	bacon@NetBSD.org
COMMENT=	C-Like 'getopt' Behavior
LICENSE=	gnu-gpl-v2

R_PKGNAME=	getopt
R_PKGVER=	1.20.3

REPLACE_R=	exec/example.R

REPLACE_INTERPRETER+=	R
REPLACE.R.old=		/path/to/Rscript
REPLACE.R.new=		${PREFIX}/bin/R
REPLACE_FILES.R=	${REPLACE_R}

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
