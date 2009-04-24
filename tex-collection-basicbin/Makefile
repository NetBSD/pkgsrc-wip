# $NetBSD: Makefile,v 1.2 2009/04/24 18:26:04 minskim Exp $
# TeX Live Revision 9325

DISTNAME=	collection-basicbin
PKGNAME=	tex-${DISTNAME}-2008.9325
CATEGORIES=	print
MASTER_SITES=	# empty

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Essential binaries for TeX

DEPENDS+=	web2c-[0-9]*:../../print/web2c		# bin-bibtex
#DEPENDS+=	tex-bin-dialog-[0-9]*:../../print/tex-bin-dialog
DEPENDS+=	dvipdfm-[0-9]*:../../print/dvipdfm	# bin-dvipdfm
#DEPENDS+=	tex-bin-dvipdfmx-[0-9]*:../../print/tex-bin-dvipdfmx
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk	# bin-dvipsk
#DEPENDS+=	tex-bin-getnonfreefonts-[0-9]*:../../print/tex-bin-getnonfreefonts
#DEPENDS+=	tex-bin-gsftopk-[0-9]*:../../print/tex-bin-gsftopk
DEPENDS+=	tex-bin-kpathsea-[0-9]*:../../print/tex-bin-kpathsea
#DEPENDS+=	tex-bin-makeindex-[0-9]*:../../print/tex-bin-makeindex
DEPENDS+=	tex-bin-metafont-[0-9]*:../../fonts/tex-bin-metafont
#DEPENDS+=	tex-bin-mfware-[0-9]*:../../print/tex-bin-mfware
DEPENDS+=	texlive-tetex-[0-9]*:../../print/texlive-tetex
DEPENDS+=	tex-bin-texlive-[0-9]*:../../print/tex-bin-texlive
DEPENDS+=	tex-bin-tex-[0-9]*:../../print/tex-bin-tex
#DEPENDS+=	tex-bin-texconfig-[0-9]*:../../print/tex-bin-texconfig
DEPENDS+=	xdvik-[0-9]*:../../print/xdvik		# bin-xdvik
DEPENDS+=	tex-dvipdfmx-def-[0-9]*:../../print/tex-dvipdfmx-def
DEPENDS+=	tex-glyphlist-[0-9]*:../../fonts/tex-glyphlist
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
# texlive.infra is not needed in pkgsrc.

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
