# $NetBSD: Makefile,v 1.2 2012/10/03 21:32:45 asau Exp $

DISTNAME=	ocamlweb-1.37
CATEGORIES=	print
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/ocamlweb/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.lri.fr/~filliatr/ocamlweb/
COMMENT=	Ocamlweb is a literate programming tool for Objective Caml
#LICENSE=	# TODO: (see mk/license.mk)

#DEPENDS+=	teTeX>=3.0:../../print/teTeX
DEPENDS+=	hevea>=1.10:../../textproc/hevea

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../lang/ocaml/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
