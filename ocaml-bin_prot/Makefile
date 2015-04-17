# $NetBSD: Makefile,v 1.7 2015/04/17 22:16:02 jgoamakf Exp $

DISTNAME=	bin_prot-112.24.00
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	bin_prot
GITHUB_TAG=	112.24.00
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/bin_prot/
COMMENT=	Read and write OCaml-values in a type-safe binary protocol
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
