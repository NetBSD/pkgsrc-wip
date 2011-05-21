# $NetBSD: Makefile,v 1.3 2011/05/21 18:18:14 marko_schuetz Exp $
#

DISTNAME=	ocamlgraph-1.7
CATEGORIES=	devel
MASTER_SITES=	http://ocamlgraph.lri.fr/download/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://ocamlgraph.lri.fr/index.fr.html
COMMENT=	Ocamlgraph is a graph library for Objective Caml
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin lib/ocaml share/doc/ocamlgraph

post-install:
	${INSTALL_DATA} ${WRKSRC}/FAQ \
		${DESTDIR}${PREFIX}/share/doc/ocamlgraph
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/ocamlgraph

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
