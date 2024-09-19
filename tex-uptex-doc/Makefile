# $NetBSD$

DISTNAME=	uptex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2020
TEXLIVE_REV=	56291

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/uptex
COMMENT=	Documentation for tex-uptex

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/man

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

# installed by print/web2c
post-install:
	${RM} ${DESTDIR}${PREFIX}/man/man1/euptex.1
	${RM} ${DESTDIR}${PREFIX}/man/man1/uppltotf.1
	${RM} ${DESTDIR}${PREFIX}/man/man1/uptex.1
	${RM} ${DESTDIR}${PREFIX}/man/man1/uptftopl.1

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
