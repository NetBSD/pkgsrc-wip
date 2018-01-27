# $NetBSD: Makefile,v 1.1 2015/02/12 08:03:34 jgoamakf Exp $

DISTNAME=	pipebang-${VERS}
VERS=		110.01.00
CATEGORIES=	devel
MASTER_SITES=	https://github.com/janestreet/pipebang/archive/
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-pa_test

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/pipebang/
COMMENT=	Syntax extension to transform x |! f into f x
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
