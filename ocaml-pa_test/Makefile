# $NetBSD: Makefile,v 1.3 2015/04/17 22:31:20 jgoamakf Exp $

DISTNAME=	pa_test-112.24.00
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	pa_test
GITHUB_TAG=	112.24.00
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/pa_test/
COMMENT=	Quotation expanders for assertions
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
