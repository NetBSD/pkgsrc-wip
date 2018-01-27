# $NetBSD: Makefile,v 1.3 2014/11/21 06:14:26 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	camomile-0.8.4
CATEGORIES=	converters
MASTER_SITES=	https://github.com/downloads/yoriyuki/Camomile/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yoriyuki/Camomile/tree/master/Camomile
COMMENT=	Unicode library for ocaml
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir="${DESTDIR}${PREFIX}/lib/ocaml/site-lib"

OCAML_USE_FINDLIB=	yes

.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
